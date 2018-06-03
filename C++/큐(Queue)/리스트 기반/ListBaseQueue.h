#pragma once
#ifndef LIST_BASE_QUEUE_H
#define LIST_BASE_QUEUE_H

template<typename T>
class Node {
private:
	T data;
	Node<T> * next;
public:
	Node(void);
	Node(T data);
	T getData(void);
	void setData(T data);
	Node<T> * getNext(void);
	void setNext(Node<T> * next);

	~Node();
};

template<typename T>
class Queue {
private:
	Node<T> * front;
	Node<T> * rear;
public:
	Queue(void);
	bool IsEmpty();
	void Enqueue(T data);
	T Dequeue();
	T Peek();

	Node<T> * getFront(void);
	Node<T> * getRear(void);
};
#endif