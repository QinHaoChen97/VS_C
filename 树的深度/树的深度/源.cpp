/*
����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]��

 3
/ \
9  20
/  \
15   7

�������������� 3 ��
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
	void uptodown(TreeNode* node,int depth,int& maxdepth)//���϶��µݹ�
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