#include<iostream>
#include"Stack.h"
#include"ExpressionTree.h"
using namespace std;

void ShowNodeData(int data) {
	if (data >= 1 && data <= 9) {
		printf("%d ", data);
	}
	else {
		printf("%c ", data);
	}
}

BinaryTreeNode * MakeExpTree(const char * exp) {
	Stack stack;
	
	int len = strlen(exp);

	for (int i = 0; i < len; i++) {
		BinaryTreeNode * bt_node = new BinaryTreeNode;

		//피연산자라면
		if (isdigit(exp[i])) {
			bt_node->SetData(exp[i] - '0');//문자를 정수로 바꾸어 저장
		}
		else {
			//연산자라면
			bt_node->ConnectRightNode(stack.Pop());
			bt_node->ConnectLeftNode(stack.Pop());

			bt_node->SetData(exp[i]);
		}

		stack.Push(bt_node);
	}

	return stack.Pop();
}

int CalculationTree(BinaryTreeNode * parentNode) {

	int op1, op2;

	if (parentNode->GetLeftNode() == NULL &&
		parentNode->GetRightNode() == NULL) {
		return parentNode->GetData();
	}

	op1 = CalculationTree(parentNode->GetLeftNode());
	op2 = CalculationTree(parentNode->GetRightNode());

	switch (parentNode->GetData()) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}