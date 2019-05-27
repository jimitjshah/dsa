#include "circularqueue.h"

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue::MyCircularQueue(int k) {
	arrSize = k;
	arr = nullptr;
	numElements = 0;
	head = -1;
	tail = -1;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool
MyCircularQueue::enQueue(int value) {
	initArray();
	if (isFull()) {
		return false;
	}
	arr[(++tail) % arrSize] = value;
	numElements++;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool
MyCircularQueue::deQueue() {
	if (isEmpty()) {
		return false;
	}
	int retVal = arr[head];
	head = (++head) % arrSize;
	numElements--;
	if (numElements == 0) {
		head = -1; tail = -1;
	}
	return retVal;
}

/** Get the front item from the queue. */
int
MyCircularQueue::Front() {
	if (isEmpty()) return -1;
	return arr[head];
}

/** Get the last item from the queue. */
int
MyCircularQueue::Rear() {
	if (isEmpty()) return -1;
	return arr[tail];
}

/** Checks whether the circular queue is empty or not. */
bool
MyCircularQueue::isEmpty() {
	return (tail == -1 && head == -1);
}

/** Checks whether the circular queue is full or not. */
bool
MyCircularQueue::isFull() {
	return ((head - (((tail + 1) % arrSize) - 1)) == 1);
}

void
MyCircularQueue::initArray() {
	if (arr == nullptr) {
		arr = new int[arrSize];
	}
}


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
