/*
 * circular_buffer.c
 *
 *  Created on: Nov 10, 2014
 *      Author: sohanir
 */
#include "stdlib.h"
#include "stdio.h"
#include "circular_buffer.h"
#define BUFFER_SIZE 8
int main()
{
	CircularBuffer *que = (CircularBuffer *)malloc(sizeof(CircularBuffer));
	KeyType mykey = 0;
	int status = 0;
	que->readPointer = que->writePointer = 0;
	que->size = 0;
	que->mask = BUFFER_SIZE -1;
	//que->keys = (KeyType *)malloc(sizeof(KeyType)*BUFFER_SIZE);
	CircularBufferEnque(que, 8);
	CircularBufferEnque(que, 10);
	CircularBufferEnque(que, 12);
	CircularBufferEnque(que, 14);
	CircularBufferEnque(que, 16);
	CircularBufferEnque(que, 18);
	CircularBufferEnque(que, 20);
	CircularBufferEnque(que, 22);
	CircularBufferEnque(que, 24);
	CircularBufferPrint(que);
	status = CircularBufferDeque(que, &mykey);
	printf("Deque %d at index %d\n",mykey, (que->readPointer-1)&que->mask);
	status = CircularBufferDeque(que, &mykey);
	printf("Deque %d at index %d\n",mykey, (que->readPointer-1)&que->mask);
	CircularBufferPrint(que);
	return(status);
}

int BufferIsFull(CircularBuffer* que)
{
    int status = 0;
    if (que->size == (que->mask + 1)) {
    	status = 1;
    }
	return status;
}
int BufferIsEmpty(CircularBuffer* que)
{
	int status = 0;
    if (que->size == 0) {
    	status = 1;
    }
	return status;

}
int BufferEnque(CircularBuffer* que, KeyType k)
{
	int status = 0;
	if(BufferIsFull(que) == 1) {
		return 0;
	}
	status = 1;
	que->keys[que->writePointer] = k;
	que->writePointer += 1;
	que->writePointer &= que->mask;
	que->size++;
	return status;
}
int BufferDeque(CircularBuffer* que, KeyType* pK)
{
	int status = 0;
	if (BufferIsEmpty(que) == 1) {
		status = 0;
	} else {
        *pK = que->keys[que->readPointer];
        que->readPointer += 1;
        que->readPointer &= que->mask;
        status = 1;
        que->size--;
	}
	return status;
}
int BufferPrint(CircularBuffer* que)
{
    int i, status = 0;
    printf("Elements of circular buffer of size %d\n", que->size);
    printf("Read Pointer %d, Write Pointer %d\n", que->readPointer, que->writePointer);
    i = que->readPointer;
    for (i = que->readPointer; i <= ((que->readPointer + que->size - 1)&que->mask); i++) {
    	printf("Element at index %d is %d\n", i, que->keys[i&que->mask]);
    	status = 1;
    }
    return status;
}
