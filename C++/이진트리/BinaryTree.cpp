#include"BinaryTree.h"
#include<iostream>
using namespace std;

//생성자 함수 호출
Node::Node(Data data) : right(NULL), left(NULL)
{
	this->data = data;
}

//노드의 데이터 값 반환
Data Node::GetData()
{
	return this->data;
}
//오른쪽 노드(서브트리)의 주소값 반환 
Node * Node::GetRightNode()
{
	return this->right;
}
//왼쪽 노드(서브트리)의 주소값 반환
Node * Node::GetLeftNode()
{
	return this->left;
}

void Node::ConnectRightNode(Node * n)
{
	if (right != NULL)
		DeleteSTree(n); //n에 연결되어 있는 서브트리를 모두 삭제

	right = n;
}

void Node::ConnectLeftNode(Node * n)
{
	if (left != NULL)
		DeleteSTree(n);

	left = n;
}

//전위 순회
void PreOrderTraversal(Node * pNode)
{
	if (pNode == NULL)
		return;

	cout << "Visited Node's Data: " << pNode->GetData() << endl;
	PreOrderTraversal(pNode->GetLeftNode());
	PreOrderTraversal(pNode->GetRightNode());
}
//중위 순회
void InOrderTraversal(Node * pNode)
{
	if (pNode == NULL)
		return;

	InOrderTraversal(pNode->GetLeftNode());
	cout << "Visited Node's Data: " << pNode->GetData() << endl;
	InOrderTraversal(pNode->GetRightNode());
}
//후위 순회
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
