#include<iostream>
#include"ListBaseQueue.h"
using namespace std;

template<typename T>
Node<typename T>::Node(void): next(NULL){}

template<typename T>
Node<typename T>::Node(T data) : next(NULL) {
	this->data = data;
}

template<typename T>
T Node<typename T>::getData(void) {
	return this->data;
}

template<typename T>
void Node<typename T>::setData(T data) {
	this->data = data;
}

template<typename T>
Node<T> * Node<typename T>::getNext(void) {
	return this->next;
}

template<typename T>
void Node<typename T>::setNext(Node<T> * next) {
	this->next = next;
}

template<typename T>
Node<typename T>::~Node() {
	cout << "노드가 삭제되었습니다." << endl;
}

template<typename T>
Queue<typename T>::Queue(void) : front(NULL), rear(NULL) { }

template<typename T>
bool Queue<typename T>::IsEmpty() {
	if (this->front == NULL) { //텅 빈 상황은 front가 NULL인 경우
		return true;
	}
	return false;
}

template<typename T>
void Queue<typename T>::Enqueue(T data) {
	Node<T> * newNode = new Node<T>;
	newNode->setData(data);
	newNode->setNext(NULL);

	if (this->front == NULL)
		this->front = newNode;
	else
		this->rear->setNext(newNode);

	this->rear = newNode;
}

template<typename T>
T Queue<typename T>::Dequeue() {
	if (IsEmpty()) {
		cout << "Dequeue exception!!" << endl;
		exit(-1);
	}
	Node<T> * delNode = this->front;
	T delData = delNode->getData();

	this->front = this->front->getNext();

	delete delNode;
	return delData;
}

template<typename T>
T Queue<typename T>::Peek() {
	if (IsEmpty()) {
		cout << "Peek exception!!" << endl;
		exit(-1);
	}

	return this->front->data;
}

template<typename T>
Node<T> * Queue<typename T>::getFront(void) {
	return this->front;
}

template<typename T>
Node<T> * Queue<typename T>::getRear(void) {
	return this->rear;
}