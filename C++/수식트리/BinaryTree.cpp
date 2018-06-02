#include"BinaryTree.h"
#include<iostream>
using namespace std;

//������ �Լ� ȣ��
BinaryTreeNode::BinaryTreeNode() : right(NULL), left(NULL) { }
BinaryTreeNode::BinaryTreeNode(BTData data) : right(NULL), left(NULL)
{
	this->data = data;
}

//����� ������ �� ����
void BinaryTreeNode::SetData(BTData data)
{
	this->data = data;
}

//����� ������ �� ��ȯ
BTData BinaryTreeNode::GetData()
{
	return this->data;
}
//������ ���(����Ʈ��)�� �ּҰ� ��ȯ 
BinaryTreeNode * BinaryTreeNode::GetRightNode()
{
	return this->right;
}
//���� ���(����Ʈ��)�� �ּҰ� ��ȯ
BinaryTreeNode * BinaryTreeNode::GetLeftNode()
{
	return this->left;
}

void BinaryTreeNode::ConnectRightNode(BinaryTreeNode * n)
{
	if (right != NULL)
		DeleteSTree(n); //n�� ����Ǿ� �ִ� ����Ʈ���� ��� ����

	right = n;
}

void BinaryTreeNode::ConnectLeftNode(BinaryTreeNode * n)
{
	if (left != NULL)
		DeleteSTree(n);

	left = n;
}

//���� ��ȸ
void PreOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int))
{
	if (pNode == NULL)
		return;

	ShowNodeData(pNode->GetData());
	PreOrderTraversal(pNode->GetLeftNode(), ShowNodeData);
	PreOrderTraversal(pNode->GetRightNode(), ShowNodeData);
}
//���� ��ȸ
void InOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int))
{
	if (pNode == NULL)
		return;

	InOrderTraversal(pNode->GetLeftNode(), ShowNodeData);
	ShowNodeData(pNode->GetData());
	InOrderTraversal(pNode->GetRightNode(), ShowNodeData);
}
//���� ��ȸ
void PostOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int))
{
	if (pNode == NULL)
		return;

	PostOrderTraversal(pNode->GetLeftNode(), ShowNodeData);
	PostOrderTraversal(pNode->GetRightNode(), ShowNodeData);
	ShowNodeData(pNode->GetData());
}

void DeleteSTree(BinaryTreeNode * pNode)
{
	if (pNode == NULL)
		return;

	DeleteSTree(pNode->GetLeftNode());
	DeleteSTree(pNode->GetRightNode());
	delete pNode;
}