/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

*/
#include<iostream>
#include<vector>
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
	bool isValidBST(TreeNode* root) {
		if (root==NULL)
		{
			return true;
		}
		vector<int> sortlist;
		recur(root, sortlist);
		if (sortlist.size()<=1)
		{
			return true;
		}
		for (int i = 1; i < sortlist.size(); i++)
		{
			if (sortlist[i]<=sortlist[i-1])//如果中序遍历不是递增序列，说明不是二叉搜索树
			{
				return false;
			}
		}
		return true;
	}
	void recur(TreeNode* root,vector<int> &sortlist)
	{
		if (root!=NULL)
		{
			recur(root->left,sortlist);
		}
		else
		{
			return;
		}
		sortlist.push_back(root->val);
		recur(root->right, sortlist);
		return;
	}
};
int main()
{
	TreeNode* a=new TreeNode(2);
	a->left = new TreeNode(1);
	a->right = new TreeNode(3);
	Solution b;
	b.isValidBST(a);
	cin.get();
}