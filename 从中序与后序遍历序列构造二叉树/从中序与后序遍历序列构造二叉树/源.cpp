/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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
			hashmap[inorder[i]] = i;//要通过键值来找位置
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
	vector<int> inorder, postorder;//用于记录存入的数组
	map<int, int> hashmap;//使用hashmap来查找以降低复杂度
};
int main()
{
	vector<int> in = { 9,3,15,20,7 };
	vector<int> post = { 9,15,7,20,3 };
	Solution a;
	a.buildTree(in, post);
	cin.get();
}