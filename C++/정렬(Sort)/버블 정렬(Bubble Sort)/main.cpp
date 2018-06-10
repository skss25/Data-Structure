#include<iostream>
#include"BubbleSort.h"
#include"BubbleSort.cpp"
using namespace std;

template<class T>
int CompareFunction(T data1, T data2) {
	return data2 - data1;
}

int main(void) {
	Sort<int> sort;

	sort.insert(4);
	sort.insert(5);
	sort.insert(2);
	sort.insert(7);
	sort.insert(1);

	cout << "정렬" << endl;
	for (int i = 0, len = sort.size(); i < len; i++) {
		cout << ++sort << " ";
	}
	
	sort.end();
	cout << endl << endl;

	cout << "역방향 출력" << endl;
	for (int i = 0, len = sort.size(); i < len; i++) {
		cout << --sort << " ";
	}
	
	sort.Ascending_BubbleSort(CompareFunction<int>);
	sort.begin();
	cout << endl << endl;
	
	cout << "오름차순 버블 정렬(Bubble Sort)" << endl;
	for (int i = 0, len = sort.size(); i < len; i++) {
		cout << ++sort << " ";
	}
	
	sort.Descending_BubbleSort(CompareFunction<int>);
	sort.begin();
	cout << endl << endl;
	
	cout << "내림차순 버블 정렬(Bubble Sort)" << endl;
	for (int i = 0, len = sort.size(); i < len; i++) {
		cout << ++sort << " ";
	}

	cout << endl << endl;
	return 0;
}