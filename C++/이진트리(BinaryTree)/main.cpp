#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main(void)
{
	//��� ����
	Node rootNode(1);
	Node Node1(2);
	Node Node2(3);
	Node Node3(4);

	//��Ʈ��忡 �� ���� ��带 ����
	rootNode.ConnectLeftNode(&Node1);
	rootNode.ConnectRightNode(&Node2);

	Node1.ConnectLeftNode(&Node3);
	return 0;
}