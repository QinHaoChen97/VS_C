/*
https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/3/solve-problems-recursively/14/
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		vector<int> vec;
		path(root, 0, vec);
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]==sum)
			{
				return true;
			}
		}
		//如果遍历了所有叶子节点路径都找不到sum
		return false;
	}
	void path(TreeNode *node,int pathsum,vector<int> &vec)//自顶向下
	{
		if (node==NULL)
		{
			return;
		}
		else
		{
			if (node->left==NULL && node->right==NULL)//是叶子节点
			{
				vec.push_back(node->val + pathsum);
				return;
			}
			else//不是叶子节点
			{
				path(node->left, pathsum + node->val, vec);
				path(node->right, pathsum + node->val, vec);
				return;
			}
		}
	}

};