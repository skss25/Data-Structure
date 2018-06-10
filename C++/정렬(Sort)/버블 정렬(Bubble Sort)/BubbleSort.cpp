#include"BubbleSort.h"
#include<iostream>
using namespace std;

template<class T>
Sort<T>::Sort(void) : numOfData(0), idx(0) {
	this->ComparingStandard = nullptr;
}

template<class T>
void Sort<T>::insert(T data) {
	if (this->numOfData == ARR_LEN) {
		cout << "Array Memory Exception!!" << endl;
		exit(-1);
	}

	this->arr[this->numOfData++] = data;
}

template<class T>
int Sort<T>::size(void) {
	return this->numOfData;
}

template<class T>
void Sort<T>::begin() {
	this->idx = 0;
}

template<class T>
void Sort<T>::end() {
	this->idx = this->numOfData - 1;
}

template<class T>
T Sort<T>::operator++() {
	return this->arr[idx++];
}
template<class T>
T Sort<T>::operator--() {
	return this->arr[idx--];
}
template<class T>
void Sort<T>::Ascending_BubbleSort(int(*Ascending)(T, T)) {
	this->ComparingStandard = Ascending;
	T temp;
	//데이터 N개가 주어졌을때, N-1회 진행
	for (int i = 0, len = this->numOfData; i < (len - 1); i++) {
		for (int j = 0; j < (len - i) - 1; j++) {
			//j번째 요소보다 j+1번째 요소가 더 우선 순위 높은 경우(값이 작은 경우) 교환
			if (this->ComparingStandard(this->arr[j], this->arr[j + 1]) < 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template<class T>
void Sort<T>::Descending_BubbleSort(int (*Descending)(T, T)) {
	this->ComparingStandard = Descending;
	T temp = 0;
	//데이터 N개가 주어졌을때, N-1회 진행
	for (int i = 0, len = this->numOfData; i < (len - 1); i++) {
		for (int j = 0; j < (len - i) - 1; j++) {
			//j+1번째 요소보다 j번째 요소가 더 우선 순위 높은 경우(값이 큰 경우) 교환
			if (this->ComparingStandard(this->arr[j], this->arr[j + 1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}