#include<iostream>
#include"ArrayBaseCircularQueue.h"
using namespace std;

int getNextIdx(int idx) //배열의 끝에 오면, 다시 0으로
{
	if ((idx + 1) == QUE_LEN) 
		return 0;
	else
		return (idx + 1);
}

template<typename T>
Queue<typename T>::Queue(void)
{
	this->front = 0;
	this->rear = 0;
}

template<typename T>
bool Queue<typename T>::IsEmpty(void)
{
	if (this->front == this->rear) //텅 빈 상황이라면...
		return true;
	else 
		return false;
}

template<typename T>
void Queue<typename T>::Enqueue(T data)
{
	if (getNextIdx(this->rear) == this->front) //데이터가 꽉 찬다면..
	{
		cout << "더 이상 데이터를 삽입할 수 없음" << endl;
		exit(-1);
	}

	//이동->데이터 저장
	this->rear++;
	this->arr[this->rear] = data;
}

template<typename T>
T Queue<typename T>::Dequeue(void)
{
	if (IsEmpty())
	{
		cout << "큐가 비어있습니다." << endl;
		exit(-1);
	}

	this->front++;
	return this->arr[this->front];
}

template<typename T>
T Queue<typename T>::Peek(void)
{
	if (IsEmpty())
	{
		cout << "큐가 비어있습니다." << endl;
		exit(-1);
	}

	return this->arr[this->front];
}