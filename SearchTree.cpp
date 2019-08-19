#include "stdafx.h"
#include "SearchTree.h"

#include <iostream>

void SearchTree::printTree(TreeNode *&root, int r)
{
	if (root != nullptr)
	{
		printTree(root->right_, r + 5);
		for (int i = 0; i < r; i++)
			printf(" ");
		printf("%d\n", root->data_);
		printTree(root->left_, r + 5);
	}
}

void SearchTree::deleteTree(TreeNode *&root)
{
	if (root == nullptr)
		return;
	deleteTree(root->left_);
	deleteTree(root->right_);
	delete root;
	root = nullptr;
}

bool SearchTree::isEmpty(TreeNode *root)
{
	return (root == nullptr);
}

int SearchTree::find(int val, TreeNode *root)
{
	if (!root)
		return 0;
	if (root->data_ > val) {
		find(val, root->left_);
	}
	else if (root->data_ < val) {
		find(val, root->right_);
	}
	else {
		return val;
	}
}


TreeNode *SearchTree::findNode(int val, TreeNode *root)
{
	while (root) {
		if (root->data_ > val) {
			root = root->left_;
			continue;
		}
		else if (root->data_ < val) {
			root = root->right_;
			continue;
		}
		else {
			return root;
		}
	}
	return nullptr;
}

void SearchTree::addNode(int val, TreeNode *&root)
{
	if (root == nullptr)
		root = new TreeNode(val);
	if (root->data_ < val)
	{
		if (root->right_ != nullptr)
			addNode(val, root->right_);
		else
			root->right_ = new TreeNode(val);
		balance(root->right_);
	}
	else
	{
		if (root->left_ != nullptr)
			addNode(val, root->left_);
		else
			root->left_ = new TreeNode(val);
		balance(root->left_);
	} 
	return;
}

TreeNode * SearchTree::deleteNode(int val, TreeNode *root)
{
	if (!root)
		return nullptr;
	if (root->data_ > val)
	{
		root->left_ = deleteNode(val, root->left_);
		return root;
	}
	else if (root->data_ < val)
	{
		root->right_ = deleteNode(val, root->right_);
		return root;
	}
	else
	{
		if (root->left_ && root->right_)
		{
			TreeNode *tmp = getMaxNode(root->left_);
			root->data_ = tmp->data_;
			root->left_ = deleteNode(tmp->data_, root->left_);
			return root;
		}
		else if (root->left_)
		{
			TreeNode *tmp = root->left_;
			root->left_ = nullptr;
			return tmp;
		}
		else if (root->right_)
		{
			TreeNode *tmp = root->right_;
			root->right_ = nullptr;
			return tmp;
		}
		else
		{
			delete root;
			root = nullptr;
			return nullptr;
		}
	}
}

TreeNode *SearchTree::getMinNode(TreeNode *root)
{
	if (root == nullptr)
		return nullptr;
	if (root->left_)
		root = getMinNode(root->left_);
	return root;
}

TreeNode *SearchTree::getMaxNode(TreeNode *root)
{
	if (root == nullptr)
		return nullptr;
	if (root->right_)
		root = getMaxNode(root->right_);
	return root;
}

TreeNode * SearchTree::rrRotation(TreeNode * root)
{
	TreeNode *tmp = root->right_;
	root->right_ = tmp->left_;
	tmp->left_ = root;
	return tmp;
}

TreeNode * SearchTree::llRotation(TreeNode * root)
{
	TreeNode * tmp = root->left_;
	root->left_ = tmp->right_;
	tmp->left_ = root;
	return tmp;
}

TreeNode * SearchTree::rlRotation(TreeNode * root)
{
	TreeNode *tmp = root->right_;
	root->right_ = llRotation(tmp);
	return rrRotation(root);
}

TreeNode * SearchTree::lrRotation(TreeNode * root)
{
	TreeNode *tmp = root->left_;
	root->left_ = rrRotation(tmp);
	return llRotation(root);
}

TreeNode * SearchTree::balance(TreeNode * root)
{
	int bal = diffTree(root);
	if (bal > 1)
	{
		if (diffTree(root->left_) > 0)
			root = llRotation(root);
		else 
			root = lrRotation(root);
	}
	else if (bal < -1)
	{
		if (diffTree(root->right_) > 0)
			root = rrRotation(root);
		else
			root = rlRotation(root);
	}
	return root;
}

int SearchTree::diffTree(TreeNode * root)
{
	int l_h = heightTree(root->left_);
	int r_h = heightTree(root->right_);
	return (l_h - r_h);
}

int SearchTree::heightTree(TreeNode * root)
{
	int h = 0;
	if (root)
	{
		int lh = heightTree(root->left_);
		int rh = heightTree(root->right_);
		int max = lh > rh ? lh : rh;
		h = max + 1;
	}
	return h;
}
