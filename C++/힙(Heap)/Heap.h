#pragma once
#ifndef HEAP_H
#define HEAP_H

#define HEAP_LEN 100
//����� Ž���� �̿��� ��� �迭�� ����Ѵ�.
template<class T>
class Heap {
private:
	T heapArr[HEAP_LEN];
	int numOfData;
	//�Լ� ������ ����
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