#include"BinaryTree.h"
#include<iostream>
using namespace std;

//생성자 함수 호출
BinaryTreeNode::BinaryTreeNode() : right(NULL), left(NULL) { }
BinaryTreeNode::BinaryTreeNode(BTData data) : right(NULL), left(NULL)
{
	this->data = data;
}

//노드의 데이터 값 저장
void BinaryTreeNode::SetData(BTData data)
{
	this->data = data;
}

//노드의 데이터 값 반환
BTData BinaryTreeNode::GetData()
{
	return this->data;
}
//오른쪽 노드(서브트리)의 주소값 반환 
BinaryTreeNode * BinaryTreeNode::GetRightNode()
{
	return this->right;
}
//왼쪽 노드(서브트리)의 주소값 반환
BinaryTreeNode * BinaryTreeNode::GetLeftNode()
{
	return this->left;
}

void BinaryTreeNode::ConnectRightNode(BinaryTreeNode * n)
{
	if (right != NULL)
		DeleteSTree(n); //n에 연결되어 있는 서브트리를 모두 삭제

	right = n;
}

void BinaryTreeNode::ConnectLeftNode(BinaryTreeNode * n)
{
	if (left != NULL)
		DeleteSTree(n);

	left = n;
}

//전위 순회
void PreOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int))
{
	if (pNode == NULL)
		return;

	ShowNodeData(pNode->GetData());
	PreOrderTraversal(pNode->GetLeftNode(), ShowNodeData);
	PreOrderTraversal(pNode->GetRightNode(), ShowNodeData);
}
//중위 순회
void InOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int))
{
	if (pNode == NULL)
		return;

	InOrderTraversal(pNode->GetLeftNode(), ShowNodeData);
	ShowNodeData(pNode->GetData());
	InOrderTraversal(pNode->GetRightNode(), ShowNodeData);
}
//후위 순회
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