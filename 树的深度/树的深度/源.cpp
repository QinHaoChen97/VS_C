/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

 3
/ \
9  20
/  \
15   7

返回它的最大深度 3 。
*/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :left(NULL), right(NULL), val(x) {};
};
class Solution {
public:
	int maxDepth(TreeNode* root) {
		int maxdepth=0;
		return maxdepth=downtoup(root);
	}
	void uptodown(TreeNode* node,int depth,int& maxdepth)//自上而下递归
	{
		if (node!=NULL)
		{
			uptodown(node->left,depth+1,maxdepth);
			uptodown(node->right,depth+1,maxdepth);
		}
		else
		{
			maxdepth=max(depth, maxdepth);
		}
	}
	int downtoup(TreeNode* node)
	{
		if (node==NULL)
		{
			return 0;
		}
		else
		{
			int maxleftdepth=downtoup(node->left);
			int maxrightdepth=downtoup(node->right);
			return max(maxleftdepth, maxrightdepth)+1;
		}
	}
};