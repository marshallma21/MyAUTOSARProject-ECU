
/*
 *  A circular buffer implementation for Rte fifos.*
 */

#include "Os.h"
#include "Rte_Fifo.h"

//lint -e160 warning only viable if in c++
//lint -e9008 The comma operator is acceptable even with loss of readability
//lint --e{9016} correct arithmetic even if Array index is not used
//lint -e9032 Composite expression with smaller essential type than other operand ok

/* IMPROVMENT: Make it threadsafe, add DisableAllInterrts()/EnableAllInterrupts() */
void Rte_Fifo_Init(RteFifoType *fBuf, void *buffer, uint8 maxCnt, size_t dataSize) {
    fBuf->bufStart = buffer;
    fBuf->maxCnt = maxCnt;/*lint !e970 modifier used*/
    fBuf->bufEnd = (char_t*) fBuf->bufStart + (((uint8) dataSize) * maxCnt);
    fBuf->head = fBuf->bufStart;
    fBuf->tail = fBuf->bufStart;
    fBuf->dataSize = dataSize;
    fBuf->currCnt = 0;
}

//lint --e{9016} correct arithmetic even if Array index is not used
Std_ReturnType Rte_Fifo_Push(RteFifoType *fPtr, void const *dataPtr) {
    SYS_CALL_SuspendOSInterrupts();
    Std_ReturnType retVal = RTE_E_OK;
    if (NULL == fPtr) {
        retVal = RTE_E_NOK; /* Faulty pointer into method */
    } else {
        if (fPtr->currCnt == fPtr->maxCnt) {
            fPtr->bufFullFlag = TRUE;
            retVal = RTE_E_LIMIT; /* No more room */
        } else {
            MEMCPY(fPtr->head, dataPtr, fPtr->dataSize);
            fPtr->head = (uint8*) fPtr->head + fPtr->dataSize; /*lint !e970 modifier used*/
            if (fPtr->head == fPtr->bufEnd) {
                fPtr->head = fPtr->bufStart;
            }
            ++fPtr->currCnt;
        }
    }
    SYS_CALL_ResumeOSInterrupts();
    return retVal;
}

/**
 * Pop an entry from the buffer.
 *
 * @param fPtr    Pointer to the queue created with CirqBuffStatCreate, etc.
 * @param dataPtr
 * @return RTE_E_OK - if successfully popped.
 *         RTE_E_NO_DATA - nothing popped (it was empty)
 *         RTE_E_LOST_DATA - if a buffer overflow has occurred previously
 */
//lint --e{9016} correct arithmetic even if Array index is not used
Std_ReturnType Rte_Fifo_Pop(RteFifoType *fPtr, void *dataPtr) {
    SYS_CALL_SuspendOSInterrupts();
    Std_ReturnType retVal = RTE_E_OK;
    if ((NULL == fPtr) || (fPtr->currCnt == 0)) {
        retVal = RTE_E_NO_DATA;
    } else {
        MEMCPY(dataPtr, fPtr->tail, fPtr->dataSize);
        fPtr->tail = (uint8*) fPtr->tail + fPtr->dataSize; /*lint !e970 modifier used */
        if (fPtr->tail == fPtr->bufEnd) {
            fPtr->tail = fPtr->bufStart;
        }
        --fPtr->currCnt;

        if (TRUE == fPtr->bufFullFlag) {
            fPtr->bufFullFlag = FALSE;
            retVal = RTE_E_LOST_DATA;
        }
    }

    SYS_CALL_ResumeOSInterrupts();
    return retVal;
}

