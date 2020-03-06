/*
����һ������������������ ���� ������

ʾ��:

����: [1,null,2,3]
1
\
2
/
3

���: [3,2,1]
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
//��������ٸ�
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> treeval;
		recuisive(root, treeval);
		return treeval;
	}
	void repostorderTraversal(TreeNode* root, vector<int> &treeval)
	{
		if (root != NULL)//�ڵ㲻�������������ڵ�
		{
			repostorderTraversal(root->left, treeval);
		}
		else//�սڵ���ʼ���˵����ڵ�
		{
			return;
		}
		repostorderTraversal(root->right,treeval);//����ѹ���ҽڵ�
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
			TreeNode* last = root;//��һ�����ʵĽڵ㣬�����ж��Ƿ�Ӧ�÷��ʸ��ڵ��ˣ�������
			while (!st.empty())
			{
				now = st.top();
				if ((now->left == NULL && now->right == NULL) || (now->left == last && now->right == NULL) || (now->right == last))//Ӧ�÷��ʱ��ڵ�����
				{
					//����Ҷ�ӽڵ㣩���ߣ���ڵ��Ѿ����ʶ��ҽڵ�Ϊ�գ����ߣ����ҽڵ㶼�ѷ��ʣ�
					st.pop();
					treeval.push_back(now->val);
					last = now;
				}
				else
				{
					now = st.top();
					if (now->right!=NULL)//��Ϊջ���Ƚ����������Ӧ���ȷ����ҽڵ� 
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