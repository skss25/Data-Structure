#include<iostream>
#include"ArrayBaseCircularQueue.h"
using namespace std;

int main(void) {
	Queue que;

	//Insert data
	cout << "Enqueue called!" << endl;
	que.Enqueue(10);
	que.Enqueue(20);
	que.Enqueue(30);
	que.Enqueue(40);
	//remove data
	cout << "Dequeue called!" << endl;
	while (!que.IsEmpty()) {
		cout << que.Dequeue() <<" ";
	}

	cout << endl;
	return 0;
}