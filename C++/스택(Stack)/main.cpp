#include<iostream>
#include"Stack.h"
using namespace std;

int main(void) {

	Stack stack;

	//Call Push()
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);

	//Call Peek()
	cout << "Call Peek()" << endl;
	cout << "stack data: " << stack.Peek() << endl << endl;

	//Call Pop()
	cout << "Call Pop()" << endl;
	while (!stack.IsEmpty()) {
		cout << stack.Pop() << " ";
	}
	cout << endl;
	
	return 0;
}