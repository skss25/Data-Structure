#pragma once
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include"BinaryTree.h"

void ShowNodeData(int data);
//������ �ԷµǸ�, ����Ʈ���� ��Ʈ ��� ��ȯ�ϴ� �Լ�
BinaryTreeNode * MakeExpTree(const char * exp); 
//Ʈ���� ��ȸ�Ͽ� ������ �����ϴ� �Լ�
int CalculationTree(BinaryTreeNode * parentNode);
#endif