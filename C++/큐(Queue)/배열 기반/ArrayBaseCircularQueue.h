#pragma once
#ifndef ARRAY_CIRCULAR_QUEUE_H
#define ARRAY_CIRCULAR_QUEUE_H

#define QUE_LEN 100
typedef int Data;

class Queue {
private:
	int front;
	int rear;
	Data arr[QUE_LEN];
public:
	Queue(void);
	bool IsEmpty(void);
	void Enqueue(Data data);
	Data Dequeue(void);
	Data Peek(void);
};

#endif