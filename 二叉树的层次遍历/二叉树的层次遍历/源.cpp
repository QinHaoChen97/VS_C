/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��

����:
����������: [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
�������α��������

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
			//���ö����Ƚ��ȳ��Ĺ�ϵ
			vector<vector<int>> levelNode;
			queue<TreeNode*> qu_one,qu_two;//��������������ʵ�ֲ��
			qu_one.push(root);
			vector<int> level;
			while (!qu_one.empty() || !qu_two.empty())
			{
				if (!qu_one.empty())//����Ƕ���һ���գ���������нڵ㲢���ӽڵ�������ж�
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