/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
返回其层次遍历结果：

[
[3],
[9,20],
[15,7]
]
*/
#include<iostream>
#include<vector>
#include<queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root==NULL)
		{
			return{};
		}
		else
		{
			//利用队列先进先出的关系
			vector<vector<int>> levelNode;
			queue<TreeNode*> qu_one,qu_two;//借助两个队列来实现层次
			qu_one.push(root);
			vector<int> level;
			while (!qu_one.empty() || !qu_two.empty())
			{
				if (!qu_one.empty())//如果是队列一不空，则遍历队列节点并把子节点推入队列二
				{
					while (!qu_one.empty())
					{
						TreeNode* Node = qu_one.front();
						qu_one.pop();
						if (Node->left!=NULL)
						{
							qu_two.push(Node->left);
						}
						if (Node->right!=NULL)
						{
							qu_two.push(Node->right);
						}
						level.push_back(Node->val);
					}
					levelNode.push_back(level);
					level.clear();
				}
				else
				{
					while (!qu_two.empty())
					{
						TreeNode* Node = qu_two.front();
						qu_two.pop();
						if (Node->left != NULL)
						{
							qu_one.push(Node->left);
						}
						if (Node->right != NULL)
						{
							qu_one.push(Node->right);
						}
						level.push_back(Node->val);
					}
					levelNode.push_back(level);
					level.clear();
				}
			}
			return levelNode;
		}
	}
};
int main()
{
	TreeNode* a = new TreeNode(3);
	a->left = new TreeNode(9);
	a->right = new TreeNode(20);
	a->right->left = new TreeNode(15);
	Solution sol;
	sol.levelOrder(a);
	cin.get();
}