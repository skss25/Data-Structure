#pragma once
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include"BinaryTree.h"

void ShowNodeData(int data);
//수식이 입력되면, 수식트리의 루트 노드 반환하는 함수
BinaryTreeNode * MakeExpTree(const char * exp); 
//트리를 순회하여 연산을 진행하는 함수
int CalculationTree(BinaryTreeNode * parentNode);
#endif