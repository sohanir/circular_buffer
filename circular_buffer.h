/*
 * circular_buffer.h
 *
 *  Created on: Nov 10, 2014
 *      Author: sohanir
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_


/* Implement a circular buffer library with the following API interface */

/**< Circular Buffer Types */
typedef unsigned char INT8U;
typedef INT8U KeyType ;
typedef struct {
    INT8U writePointer ; /**< write pointer */
    INT8U readPointer ;  /**< read pointer */
    INT8U size;         /**< size of circular buffer */
    INT8U mask;         /**< bit Mask of circular buffer size*/
    KeyType keys[0];    /**< Element of circular buffer */
} CircularBuffer ;

/* Internal functions */
int BufferIsFull(CircularBuffer* que);
int BufferIsEmpty(CircularBuffer* que);
int BufferEnque(CircularBuffer* que, KeyType k);
int BufferDeque(CircularBuffer* que, KeyType *k);
int BufferPrint(CircularBuffer* que);

/* \brief Returns 1 if Buffer is full */
inline int CircularBufferIsFull(CircularBuffer* que)
{
    return(BufferIsFull(que));
}
/* \brief Returns 1 if Buffer is empty */
inline int CircularBufferIsEmpty(CircularBuffer* que)
{
    return(BufferIsEmpty(que));
}
/* \brief Adds k at the writePointer */
inline int CircularBufferEnque(CircularBuffer* que, KeyType k)
{
    return(BufferEnque(que,k));
}
/* \brief Removes and returns the element at readpointer */
inline int CircularBufferDeque(CircularBuffer* que, KeyType* pK)
{
    return(BufferDeque(que,pK));
}
/* \brief Prints elements of the buffer between
 *        Read and Write Pointer
 */
inline int CircularBufferPrint(CircularBuffer* que)
{
    return(BufferPrint(que));
}


#endif /* CIRCULAR_BUFFER_H_ */
