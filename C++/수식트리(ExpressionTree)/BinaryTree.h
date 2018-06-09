#pragma
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
//이진트리(BinaryTree.h)
typedef int BTData;

class BinaryTreeNode {
private:
	BTData data;
	BinaryTreeNode * right;
	BinaryTreeNode * left;
public:
	BinaryTreeNode();
	//생성자 함수 호출
	BinaryTreeNode(BTData data);
	//노드의 데이터 값 저장
	void SetData(BTData data);
	//노드의 데이터 값 반환
	BTData GetData();
	//오른쪽 노드(서브트리)의 주소값 반환 
	BinaryTreeNode * GetRightNode();
	//왼쪽 노드(서브트리)의 주소값 반환
	BinaryTreeNode * GetLeftNode();

	//노드를 연결한다.
	void ConnectRightNode(BinaryTreeNode * n);
	void ConnectLeftNode(BinaryTreeNode * n);
};

void PreOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int));
void InOrderTraversal(BinaryTreeNode * pNode, void (*ShowNodeData)(int));
void PostOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int));

void DeleteSTree(BinaryTreeNode * pNode);
#endif