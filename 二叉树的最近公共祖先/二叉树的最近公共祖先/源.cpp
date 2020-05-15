/*
�ⷨ�ο�
https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<iostream>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root==NULL || root==p ||root==q) //������Ҫ�ҵĽڵ㣬ֱ�ӷ���
		{
			return root;
		}
		//�����������Ϊ�����ҵ���ֱ�ӷ��أ�����ʵ���ϲ��������ĺ������
		TreeNode* left=lowestCommonAncestor(root->left, p, q);
		TreeNode* right=lowestCommonAncestor(root->right, p, q);
		if (left==NULL)//һ���ǿ���ôֱ�ӷ�����һ�ߣ���Ϊ������һ���ǿջ������ҵ��ڵ㶼�������Ӱ��
		{
			return right;
		}
		else if(right==NULL)
		{
			return left;
		}
		else//���Ҷ��ǿգ���ô˵����ʱ�Ľڵ�����������Ƚڵ�
		{
			return root;
		}
	}
};
int main()
{

}