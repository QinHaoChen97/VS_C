/*
给定一个二叉树，返回它的 前序 遍历。

示例:

输入: [1,null,2,3]
1
\
2
/
3

输出: [1,2,3]
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> treeval;
		iterapreorder(root, treeval);
		return treeval;
	}
	void repreorder(TreeNode *root, vector<int> &treeval)//递归方法实现前序遍历
	{
		if (root!=NULL)
		{
			treeval.push_back(root->val);//先访问根节点
			repreorder(root->left, treeval);
			repreorder(root->right, treeval);
		}
		else
		{
			return;
		}
	}
	void iterapreorder(TreeNode *root, vector<int> &treeval)//迭代方法实现
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			stack<TreeNode*> tree;
			tree.push(root);
			while (!tree.empty())
			{
				TreeNode* node;
				node = tree.top();
				tree.pop();
				treeval.push_back(node->val);
				if (node->right!=NULL)
				{
					tree.push(node->right);
				}
				if (node->left!=NULL)
				{
					tree.push(node->left);
				}
			}
		}
	}
};