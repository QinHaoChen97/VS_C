/*
给定一个二叉树，检查它是否是镜像对称的。



例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2    2
 / \  / \
3  4 4   3


但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode/
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :left(NULL), right(NULL), val(x) {};
};
class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if (root==NULL)
			{
				return false;
			}
			return symmetry(root->left, root->right);
		}
		void pushval(TreeNode* node, vector<int> &vec)//中序遍历,中序遍历只有在树的根结点的值都为一对一对的时候才有效,所以这个方法有缺陷，不能通过全部的测试案例
		{
			if (node==NULL)
			{
				vec.push_back(0);
				return;
			}
			else
			{
				pushval(node->left,vec);
			}
			vec.push_back(node->val);
			pushval(node->right,vec);
			return;
		}
		bool symmetry(TreeNode *nodeleft, TreeNode *noderight)//对称方法
		{
			if (nodeleft==NULL && noderight==NULL)//对称的点都为空节点
			{
				return true;
			}
			else if(nodeleft==NULL || noderight==NULL)//对称的点有一方为空节点
			{
				return false;
			}
			//对称的点都不为空节点，则先查看val是否相等，相等则继续往下递归，注意点要对称判断
			return (nodeleft->val == noderight->val) && symmetry(nodeleft->left, noderight->right) && symmetry(nodeleft->right, noderight->left);
		}

};
int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	Solution a;
	bool b = true;
	b=a.isSymmetric(root);
	cin.get();
}