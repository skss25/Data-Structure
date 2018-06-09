#include<iostream>
#include"BinaryTree.h"
#include"ExpressionTree.h"
using namespace std;

int main(void) {
	const char * exp = "123*+";

	BinaryTreeNode * expTree = MakeExpTree(exp);

	cout << "���� ǥ����� ����: ";
	PreOrderTraversal(expTree, ShowNodeData); cout << endl;

	cout << "���� ǥ����� ����: ";
	InOrderTraversal(expTree, ShowNodeData); cout << endl;

	cout << "���� ǥ����� ����: ";
	PostOrderTraversal(expTree, ShowNodeData); cout << endl;

	cout << "������ ���: " << CalculationTree(expTree) << endl;
	return 0;
}