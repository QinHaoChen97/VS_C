/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
*/
#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};
	class Solution {
	public:
		TreeNode* deleteNode(TreeNode* root, int key) {
			if (root==NULL)
			{
				return root;
			}
			if (root->val==key)
			{
				//如果没有叶子节点或没有左节点，则返回右节点（有可能是空节点）
				if (root->left==NULL)
				{
					return root->right;
				}
				else if(root->right==NULL)//如果右节点为空节点左节点不空，则删除当前节点并返回左节点
				{
					return root->left;
				}
				else//左右节点都不空,将左节点放在右节点的最左节点处，并删除当前节点返回右节点
				{
					TreeNode* cur = root->right;
					while (cur->left!=NULL)
					{
						cur = cur->left;
					}
					cur->left = root->left;
					return root->right;
				}
			}
			if (root->val>key)
			{
				root->left = deleteNode(root->left, key);
			}
			else
			{
				root->right = deleteNode(root->right, key);
			}
			return root;//在每个函数中的root是当前节点
		}
	};