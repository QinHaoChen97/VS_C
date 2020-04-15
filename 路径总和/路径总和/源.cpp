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
		//�������������Ҷ�ӽڵ�·�����Ҳ���sum
		return false;
	}
	void path(TreeNode *node,int pathsum,vector<int> &vec)//�Զ�����
	{
		if (node==NULL)
		{
			return;
		}
		else
		{
			if (node->left==NULL && node->right==NULL)//��Ҷ�ӽڵ�
			{
				vec.push_back(node->val + pathsum);
				return;
			}
			else//����Ҷ�ӽڵ�
			{
				path(node->left, pathsum + node->val, vec);
				path(node->right, pathsum + node->val, vec);
				return;
			}
		}
	}

};