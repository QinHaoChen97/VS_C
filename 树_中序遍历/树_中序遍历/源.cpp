/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
1
\
2
/
3

输出: [1,3,2]
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) :left(NULL), right(NULL), val(x) {};

};
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> treeval;
		iterationinorderTraversal(root, treeval);
		return treeval;
	}
	void reinorderTraversal(TreeNode* root, vector<int> &tree) {
		if (root!=NULL)
		{
			reinorderTraversal(root->left,tree);
			tree.push_back(root->val);
			reinorderTraversal(root->right, tree);
		}
		else
		{
			return;
		}
	}

	void iterationinorderTraversal(TreeNode* root, vector<int> &treeval) {
		if (root==NULL)
		{
			return;
		}
		stack<TreeNode*> treestack;
		TreeNode* Node = root;
		while (!treestack.empty() || Node!=NULL)//这一步比较巧妙
		{
			while (Node!=NULL)//如果节点左子树不空则一直推入
			{
				treestack.push(Node);
				Node = Node->left;
			}
			Node = treestack.top();
			treestack.pop();
			treeval.push_back(Node->val);//当左子树为空时则推入该节点，当前节点左子树为空，那么本身就是根结点，将根结点推入，即完成了先左后根
			Node = Node->right;
		}
	}

};