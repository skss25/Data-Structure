#pragma once
#ifndef STACK_H
#define STACK_H

#include"BinaryTree.h"
typedef BinaryTreeNode * Data;

class Node {
private:
	Data data;
	Node * nextNode;
public:
	Node();
	Node(Data data, Node * next);
	Node(Node &node);
	void setData(Data data);
	void setNext(Node * next);

	Data getData();
	Node * getNext();
};

class Stack {
private:
	Node * head;
	int numOfData;
public:
	Stack();
	Stack(Node * head);
	Stack(Stack &stack);
	bool IsEmpty();
	void Push(Data data);
	Data Pop();
	Data Peek();
};
#endif
