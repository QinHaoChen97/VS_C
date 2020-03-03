/*
����һ���������������������� ������

ʾ��:

����: [1,null,2,3]
1
\
2
/
3

���: [1,3,2]
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
		while (!treestack.empty() || Node!=NULL)//��һ���Ƚ�����
		{
			while (Node!=NULL)//����ڵ�������������һֱ����
			{
				treestack.push(Node);
				Node = Node->left;
			}
			Node = treestack.top();
			treestack.pop();
			treeval.push_back(Node->val);//��������Ϊ��ʱ������ýڵ㣬��ǰ�ڵ�������Ϊ�գ���ô������Ǹ���㣬����������룬�������������
			Node = Node->right;
		}
	}

};