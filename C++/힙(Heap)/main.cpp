#include<iostream>
#include"Heap.h"
#include"Heap.cpp"
using namespace std;

//��������(���� �������� �켱������ ����.)
int DataCompareFunction(int n1, int n2) {
	return n2 - n1;
}

int main(void) {
	Heap<int> heap(DataCompareFunction);

	heap.Insert(1);
	heap.Insert(2);
	heap.Insert(3);
	heap.Insert(4);
	
	while (!heap.IsEmpty())
		cout << heap.Delete() << endl;
	return 0;
}