#include"BinaryTree.h"
#include<iostream>
using namespace std;

//������ �Լ� ȣ��
Node::Node(Data data) : right(NULL), left(NULL)
{
	this->data = data;
}

//����� ������ �� ��ȯ
Data Node::GetData()
{
	return this->data;
}
//������ ���(����Ʈ��)�� �ּҰ� ��ȯ 
Node * Node::GetRightNode()
{
	return this->right;
}
//���� ���(����Ʈ��)�� �ּҰ� ��ȯ
Node * Node::GetLeftNode()
{
	return this->left;
}

void Node::ConnectRightNode(Node * n)
{
	if (right != NULL)
		DeleteSTree(n); //n�� ����Ǿ� �ִ� ����Ʈ���� ��� ����

	right = n;
}

void Node::ConnectLeftNode(Node * n)
{
	if (left != NULL)
		DeleteSTree(n);

	left = n;
}

//���� ��ȸ
void PreOrderTraversal(Node * pNode)
{
	if (pNode == NULL)
		return;

	cout << "Visited Node's Data: " << pNode->GetData() << endl;
	PreOrderTraversal(pNode->GetLeftNode());
	PreOrderTraversal(pNode->GetRightNode());
}
//���� ��ȸ
void InOrderTraversal(Node * pNode)
{
	if (pNode == NULL)
		return;

	InOrderTraversal(pNode->GetLeftNode());
	cout << "Visited Node's Data: " << pNode->GetData() << endl;
	InOrderTraversal(pNode->GetRightNode());
}
//���� ��ȸ
void PostOrderTraversal(Node * pNode)
{
	if (pNode == NULL)
		return;

	PostOrderTraversal(pNode->GetLeftNode());
	PostOrderTraversal(pNode->GetRightNode());
	cout << "Visited Node's Data: " << pNode->GetData() << endl;
}

void DeleteSTree(Node * pNode)
{
	if (pNode == NULL)
		return;

	DeleteSTree(pNode->GetLeftNode());
	DeleteSTree(pNode->GetRightNode());
	delete pNode;
}
