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
	//생성자 함수 호출
	Node(Data data);
	//노드의 데이터 값 반환
	Data GetData();
	//오른쪽 노드(서브트리)의 주소값 반환 
	Node * GetRightNode();
	//왼쪽 노드(서브트리)의 주소값 반환
	Node * GetLeftNode();

	//노드를 연결한다.
	void ConnectRightNode(Node * n);
	void ConnectLeftNode(Node * n);
};

//순회
void PreOrderTraversal(Node * pNode);
void InOrderTraversal(Node * pNode);
void PostOrderTraversal(Node * pNode);

void DeleteSTree(Node * pNode);

#endif