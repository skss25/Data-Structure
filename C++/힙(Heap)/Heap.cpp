#include"Heap.h"

template<class T>
Heap<T>::Heap(int(*fp)(T, T)) : numOfData(0){
	this->CompareFunction = fp; //힙에서 우선 순위 기준을 설정
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

	if (leftIdx > this->numOfData) //자식 노드가 없는 경우
		return 0;
	else if (leftIdx == this->numOfData)
		return leftIdx;
	else {
		if (this->CompareFunction(this->heapArr[leftIdx], 
			this->heapArr[rightIdx]) >= 0) { //왼쪽 자식 노드가 우선 순위가 큰 경우
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
	int childIdx = this->numOfData + 1; //새로운 데이터가 트리의 마지막 위치에 있다고 가정!
	int parentIdx = 0; //부모 노드의 인덱스 값

	while (childIdx != 1) {
		parentIdx = GetParentIdx(childIdx);

		if (this->CompareFunction(lastData, this->heapArr[parentIdx]) >= 0)
		{ //자식 노드가 우선 순위가 더 높은 경우

			this->heapArr[childIdx] = this->heapArr[parentIdx];
			childIdx = parentIdx;
		}
		else
			break; //교환이 발생하지 않으면, childIdx의 위치에 저장
	}

	this->heapArr[childIdx] = lastData;
	this->numOfData += 1;
}

template<class T>
T Heap<T>::Delete(void) {
	T data = this->heapArr[1];
	T lastData = this->heapArr[this->numOfData];

	int childIdx = 0;
	int parentIdx = 1; //마지막 노드보다 자식 노드가 큰 경우 이동해야할 위치

	while (childIdx = GetHighPriorityChildIdx(parentIdx)) {
		if (this->CompareFunction(lastData, this->heapArr[childIdx]) >= 0)
			break;

		//교환
		this->heapArr[parentIdx] = this->heapArr[childIdx];
		parentIdx = childIdx;
	}

	this->heapArr[parentIdx] = lastData;
	this->numOfData -= 1;
	return data;
}