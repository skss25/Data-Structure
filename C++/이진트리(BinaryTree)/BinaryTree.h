#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef int Data;

class Node {
private:
	Data data;
	Node * right;
	Node * left;
public:
	//������ �Լ� ȣ��
	Node(Data data);
	//����� ������ �� ��ȯ
	Data GetData();
	//������ ���(����Ʈ��)�� �ּҰ� ��ȯ 
	Node * GetRightNode();
	//���� ���(����Ʈ��)�� �ּҰ� ��ȯ
	Node * GetLeftNode();

	//��带 �����Ѵ�.
	void ConnectRightNode(Node * n);
	void ConnectLeftNode(Node * n);
};

//��ȸ
void PreOrderTraversal(Node * pNode);
void InOrderTraversal(Node * pNode);
void PostOrderTraversal(Node * pNode);

void DeleteSTree(Node * pNode);

#endif