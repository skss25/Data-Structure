#include<iostream>
#include"Stack.h"
using namespace std;

Node::Node() : nextNode(nullptr) { }

Node::Node(Data data, Node * next) {
	this->data = data; 
	this->nextNode = next;
}

Node::Node(Node &node) {
	this->data = node.data;
	this->nextNode = node.nextNode;
}

void Node::setData(Data data) {
	this->data = data;
}
void Node::setNext(Node * next) {
	this->nextNode = next;
}

Data Node::getData() {
	return this->data;
}

Node * Node::getNext() {
	return this->nextNode;
}

Stack::Stack() : numOfData(0), head(nullptr) { }
Stack::Stack(Node * head) {
	this->head = head;
}
Stack::Stack(Stack &stack) {
	this->head = stack.head;
}

bool Stack::IsEmpty() {
	if (this->numOfData == 0)
		return true;
	else
		return false;
}

void Stack::Push(Data data) {
	//create new node
	Node * newNode = new Node;
	newNode->setData(data);
	//connect new node to head

	newNode->setNext(this->head);
	this->head = newNode;
	this->numOfData += 1;
}

Data Stack::Pop() {
	if (IsEmpty()) {
		cout << "Pop() exception: Stack Memory Error!" << endl;
		exit(-1);
	}
	
	Node * delNode = this->head;
	Data delData = delNode->getData();

	//move down(next node)
	this->head = this->head->getNext();
	this->numOfData -= 1;

	delete []delNode;
	return delData;
}

Data Stack::Peek() {
	if (IsEmpty()) {
		cout << "Peek() exception: Stack Memory Error!" << endl;
		exit(-1);
	}

	return this->head->getData();
}