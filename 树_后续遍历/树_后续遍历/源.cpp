/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
1
\
2
/
3

输出: [3,2,1]
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};
//先左后右再根
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> treeval;
		recuisive(root, treeval);
		return treeval;
	}
	void repostorderTraversal(TreeNode* root, vector<int> &treeval)
	{
		if (root != NULL)//节点不空则持续推入左节点
		{
			repostorderTraversal(root->left, treeval);
		}
		else//空节点则开始回退到根节点
		{
			return;
		}
		repostorderTraversal(root->right,treeval);//接着压入右节点
		treeval.push_back(root->val);
	}
	void recuisive(TreeNode* root, vector<int> &treeval)
	{
		if (root==NULL)
		{
			return;
		}
		else
		{
			stack<TreeNode*> st;
			st.push(root);
			TreeNode* now = root;
			TreeNode* last = root;//上一个访问的节点，用于判断是否应该访问根节点了，很巧妙
			while (!st.empty())
			{
				now = st.top();
				if ((now->left == NULL && now->right == NULL) || (now->left == last && now->right == NULL) || (now->right == last))//应该访问本节点的情况
				{
					//（是叶子节点）或者（左节点已经访问而右节点为空）或者（左右节点都已访问）
					st.pop();
					treeval.push_back(now->val);
					last = now;
				}
				else
				{
					now = st.top();
					if (now->right!=NULL)//因为栈是先进后出，所以应该先放入右节点 
					{
						st.push(now->right);
					}
					if (now->left!=NULL)
					{
						st.push(now->left);
					}
				}
			}
		}
	}
};