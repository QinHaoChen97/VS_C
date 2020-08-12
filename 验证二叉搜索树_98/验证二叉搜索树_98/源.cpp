/*
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������

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
			if (sortlist[i]<=sortlist[i-1])//�������������ǵ������У�˵�����Ƕ���������
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