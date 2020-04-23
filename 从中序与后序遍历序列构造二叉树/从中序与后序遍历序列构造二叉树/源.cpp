/*
����һ��������������������������������

ע��:
����Լ�������û���ظ���Ԫ�ء�

���磬����

������� inorder = [9,3,15,20,7]
������� postorder = [9,15,7,20,3]
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
		{
			return NULL;
		}
		this->inorder = inorder;
		this->postorder = postorder;
		for (int i = 0; i < inorder.size(); i++)
		{
			hashmap[inorder[i]] = i;//Ҫͨ����ֵ����λ��
		}
		TreeNode* root = rebuildTree(0,inorder.size()-1,0,postorder.size()-1);
		return root;
	}
	TreeNode* rebuildTree(int inorderleft,int inorderright,int postorderleft,int postorderright)
	{
		if (inorderleft>inorderright ||postorderleft>postorderright)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder[postorderright]);
		int pos = hashmap[postorder[postorderright]];
		root->left = rebuildTree(inorderleft, pos - 1, postorderleft, pos - inorderleft + postorderleft - 1);
		root->right = rebuildTree(pos + 1, inorderright, pos - inorderleft + postorderleft, postorderright - 1);
		return root;
	}
private:
	vector<int> inorder, postorder;//���ڼ�¼���������
	map<int, int> hashmap;//ʹ��hashmap�������Խ��͸��Ӷ�
};
int main()
{
	vector<int> in = { 9,3,15,20,7 };
	vector<int> post = { 9,15,7,20,3 };
	Solution a;
	a.buildTree(in, post);
	cin.get();
}