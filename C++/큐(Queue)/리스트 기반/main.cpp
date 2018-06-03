#include<iostream>
#include"ListBaseQueue.h"
#include"ListBaseQueue.cpp"
using namespace std;

int main(void) {
	Queue<int> que;

	//Insert data
	que.Enqueue(100);
	que.Enqueue(200);
	que.Enqueue(300);
	que.Enqueue(400);

	//Remove data
	while (!que.IsEmpty()) {
		cout << que.Dequeue() << endl;
	}

	cout << endl;
	return 0;
}