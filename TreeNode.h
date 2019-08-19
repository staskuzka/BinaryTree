#pragma once

class TreeNode
{
public:
	TreeNode(int d);
	~TreeNode();

	int data_;
	TreeNode *left_;
	TreeNode *right_;
};
