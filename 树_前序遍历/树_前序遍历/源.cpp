/*
����һ������������������ ǰ�� ������

ʾ��:

����: [1,null,2,3]
1
\
2
/
3

���: [1,2,3]
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
	void repreorder(TreeNode *root, vector<int> &treeval)//�ݹ鷽��ʵ��ǰ�����
	{
		if (root!=NULL)
		{
			treeval.push_back(root->val);//�ȷ��ʸ��ڵ�
			repreorder(root->left, treeval);
			repreorder(root->right, treeval);
		}
		else
		{
			return;
		}
	}
	void iterapreorder(TreeNode *root, vector<int> &treeval)//��������ʵ��
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