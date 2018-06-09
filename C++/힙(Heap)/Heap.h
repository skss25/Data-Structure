#pragma once
#ifndef HEAP_H
#define HEAP_H

#define HEAP_LEN 100
//빈번한 탐색을 이용할 경우 배열을 사용한다.
template<class T>
class Heap {
private:
	T heapArr[HEAP_LEN];
	int numOfData;
	//함수 포인터 변수
	int(*CompareFunction)(T, T);
public:
	Heap(int(*fp)(T, T));
	void Insert(T data);
	T Delete(void);
	bool IsEmpty(void);

	int GetHighPriorityChildIdx(int parentIdx);
	int GetParentIdx(int childIdx);
	int GetLChildIdx(int parentIdx);
	int GetRChildIdx(int parentIdx);
};

#endif