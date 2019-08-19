#include "stdafx.h"
#include "TreeNode.h"

TreeNode::TreeNode(int d) :
	data_(d), left_(nullptr), right_(nullptr)
{
}

TreeNode::~TreeNode()
{
	if (left_) delete left_;
	if (right_) delete right_;
}
