#pragma once
#ifndef ARRAY_CIRCULAR_QUEUE_H
#define ARRAY_CIRCULAR_QUEUE_H

#define QUE_LEN 100

template<typename T>
class Queue {
private:
	int front;
	int rear;
	T arr[QUE_LEN];
public:
	Queue(void);
	bool IsEmpty(void);
	void Enqueue(T data);
	T Dequeue(void);
	T Peek(void);
};

#endif