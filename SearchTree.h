#pragma once
#include "TreeNode.h"

class SearchTree
{
public:
	void printTree(TreeNode *&root, int r);
	void deleteTree(TreeNode *&root);
	bool isEmpty(TreeNode *root);
	int find(int val, TreeNode *root);
	TreeNode *findNode(int val, TreeNode *root);
	void addNode(int val, TreeNode *&root);
	TreeNode *deleteNode(int val, TreeNode *root);
	TreeNode *getMinNode(TreeNode *root);
	TreeNode *getMaxNode(TreeNode *root);
	TreeNode *rrRotation(TreeNode *root);
	TreeNode *llRotation(TreeNode *root);
	TreeNode *rlRotation(TreeNode *root);
	TreeNode *lrRotation(TreeNode *root);
	TreeNode *balance(TreeNode *root);
	int diffTree(TreeNode *root);
	int heightTree(TreeNode *root);
};
