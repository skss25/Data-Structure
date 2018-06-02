#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main(void)
{
	//노드 생성
	Node rootNode(1);
	Node Node1(2);
	Node Node2(3);
	Node Node3(4);

	//루트노드에 두 개의 노드를 연결
	rootNode.ConnectLeftNode(&Node1);
	rootNode.ConnectRightNode(&Node2);

	Node1.ConnectLeftNode(&Node3);
	return 0;
}