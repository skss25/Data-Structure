#include<iostream>
#include"ArrayBaseCircularQueue.h"
using namespace std;

int getNextIdx(int idx) //�迭�� ���� ����, �ٽ� 0����
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
	if (this->front == this->rear) //�� �� ��Ȳ�̶��...
		return true;
	else 
		return false;
}

template<typename T>
void Queue<typename T>::Enqueue(T data)
{
	if (getNextIdx(this->rear) == this->front) //�����Ͱ� �� ���ٸ�..
	{
		cout << "�� �̻� �����͸� ������ �� ����" << endl;
		exit(-1);
	}

	//�̵�->������ ����
	this->rear++;
	this->arr[this->rear] = data;
}

template<typename T>
T Queue<typename T>::Dequeue(void)
{
	if (IsEmpty())
	{
		cout << "ť�� ����ֽ��ϴ�." << endl;
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
		cout << "ť�� ����ֽ��ϴ�." << endl;
		exit(-1);
	}

	return this->arr[this->front];
}