#pragma once
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#define ARR_LEN 100
template<class T>
class Sort {
private:
	T arr[ARR_LEN];
	int numOfData;
	int idx;

	int (*ComparingStandard)(T, T);
public:
	Sort(void);
	void insert(T data);
	int size(void);
	void begin();
	void end();

	T operator++();
	T operator--();

	void Ascending_BubbleSort(int (*Ascending)(T, T));
	void Descending_BubbleSort(int (*Descending)(T, T));
};

#endif