#pragma
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
//����Ʈ��(BinaryTree.h)
typedef int BTData;

class BinaryTreeNode {
private:
	BTData data;
	BinaryTreeNode * right;
	BinaryTreeNode * left;
public:
	BinaryTreeNode();
	//������ �Լ� ȣ��
	BinaryTreeNode(BTData data);
	//����� ������ �� ����
	void SetData(BTData data);
	//����� ������ �� ��ȯ
	BTData GetData();
	//������ ���(����Ʈ��)�� �ּҰ� ��ȯ 
	BinaryTreeNode * GetRightNode();
	//���� ���(����Ʈ��)�� �ּҰ� ��ȯ
	BinaryTreeNode * GetLeftNode();

	//��带 �����Ѵ�.
	void ConnectRightNode(BinaryTreeNode * n);
	void ConnectLeftNode(BinaryTreeNode * n);
};

void PreOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int));
void InOrderTraversal(BinaryTreeNode * pNode, void (*ShowNodeData)(int));
void PostOrderTraversal(BinaryTreeNode * pNode, void(*ShowNodeData)(int));

void DeleteSTree(BinaryTreeNode * pNode);
#endif