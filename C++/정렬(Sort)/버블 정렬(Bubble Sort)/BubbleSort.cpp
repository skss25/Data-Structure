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
	//������ N���� �־�������, N-1ȸ ����
	for (int i = 0, len = this->numOfData; i < (len - 1); i++) {
		for (int j = 0; j < (len - i) - 1; j++) {
			//j��° ��Һ��� j+1��° ��Ұ� �� �켱 ���� ���� ���(���� ���� ���) ��ȯ
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
	//������ N���� �־�������, N-1ȸ ����
	for (int i = 0, len = this->numOfData; i < (len - 1); i++) {
		for (int j = 0; j < (len - i) - 1; j++) {
			//j+1��° ��Һ��� j��° ��Ұ� �� �켱 ���� ���� ���(���� ū ���) ��ȯ
			if (this->ComparingStandard(this->arr[j], this->arr[j + 1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}