#include"Heap.h"

template<class T>
Heap<T>::Heap(int(*fp)(T, T)) : numOfData(0){
	this->CompareFunction = fp; //������ �켱 ���� ������ ����
}

template<class T>
bool Heap<T>::IsEmpty(void) {
	if (this->numOfData == 0)
		return true;
	else
		return false;
}

template<class T>
int Heap<T>::GetHighPriorityChildIdx(int parentIdx) {
	int leftIdx = GetLChildIdx(parentIdx);
	int rightIdx = GetRChildIdx(parentIdx);

	if (leftIdx > this->numOfData) //�ڽ� ��尡 ���� ���
		return 0;
	else if (leftIdx == this->numOfData)
		return leftIdx;
	else {
		if (this->CompareFunction(this->heapArr[leftIdx], 
			this->heapArr[rightIdx]) >= 0) { //���� �ڽ� ��尡 �켱 ������ ū ���
			return leftIdx;
		}
		else
			return rightIdx;
	}
}

template<class T>
int Heap<T>::GetParentIdx(int childIdx) {
	return childIdx / 2;
}

template<class T>
int Heap<T>::GetLChildIdx(int parentIdx) {
	return parentIdx * 2;
}

template<class T>
int Heap<T>::GetRChildIdx(int parentIdx) {
	return (parentIdx * 2) + 1;
}

template<class T>
void Heap<T>::Insert(T lastData) {
	int childIdx = this->numOfData + 1; //���ο� �����Ͱ� Ʈ���� ������ ��ġ�� �ִٰ� ����!
	int parentIdx = 0; //�θ� ����� �ε��� ��

	while (childIdx != 1) {
		parentIdx = GetParentIdx(childIdx);

		if (this->CompareFunction(lastData, this->heapArr[parentIdx]) >= 0)
		{ //�ڽ� ��尡 �켱 ������ �� ���� ���

			this->heapArr[childIdx] = this->heapArr[parentIdx];
			childIdx = parentIdx;
		}
		else
			break; //��ȯ�� �߻����� ������, childIdx�� ��ġ�� ����
	}

	this->heapArr[childIdx] = lastData;
	this->numOfData += 1;
}

template<class T>
T Heap<T>::Delete(void) {
	T data = this->heapArr[1];
	T lastData = this->heapArr[this->numOfData];

	int childIdx = 0;
	int parentIdx = 1; //������ ��庸�� �ڽ� ��尡 ū ��� �̵��ؾ��� ��ġ

	while (childIdx = GetHighPriorityChildIdx(parentIdx)) {
		if (this->CompareFunction(lastData, this->heapArr[childIdx]) >= 0)
			break;

		//��ȯ
		this->heapArr[parentIdx] = this->heapArr[childIdx];
		parentIdx = childIdx;
	}

	this->heapArr[parentIdx] = lastData;
	this->numOfData -= 1;
	return data;
}