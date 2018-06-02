#include<iostream>
#include"BinaryTree.h"
#include"ExpressionTree.h"
using namespace std;

int main(void) {
	const char * exp = "123*+";

	BinaryTreeNode * expTree = MakeExpTree(exp);

	cout << "전위 표기법의 수식: ";
	PreOrderTraversal(expTree, ShowNodeData); cout << endl;

	cout << "중위 표기법의 수식: ";
	InOrderTraversal(expTree, ShowNodeData); cout << endl;

	cout << "후위 표기법의 수식: ";
	PostOrderTraversal(expTree, ShowNodeData); cout << endl;

	cout << "연산의 결과: " << CalculationTree(expTree) << endl;
	return 0;
}