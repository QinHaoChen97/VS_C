/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。


解法参考https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/qian-xu-bian-li-python-dai-ma-java-dai-ma-by-liwei/
分而治之
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int prelength = preorder.size();
		int inlength = inorder.size();
		if (prelength!=inlength ||prelength==0)//前序遍历和中序遍历的节点数不一致或者是空二叉树
		{
			return NULL;
		}
		this->preorder = preorder;
		this->inorder = inorder;
		for (int i = 0; i < prelength; i++)//将中序遍历放入哈希表，键值为树的val
		{
			hashmap[inorder[i]] = i;
		}
		int pos = hashmap[preorder[0]];//获得根节点的下标
		TreeNode* root = new TreeNode(preorder[0]);
		root->left = rebuildTree(0 + 1, 0 + pos - 0, 0, pos - 1);
		root->right = rebuildTree(0 + pos - 0 + 1, prelength - 1, pos + 1, inlength - 1);
		return root;
	}
	TreeNode* rebuildTree(int preleft, int preright,int inleft,int inright)
	{
		if (preleft>preright || inleft>inright)
		{
			return NULL;
		}
		else
		{
			TreeNode* root = new TreeNode(preorder[preleft]);
			int pos = hashmap[preorder[preleft]];
			root->left = rebuildTree(preleft + 1, pos - inleft+preleft, inleft, pos - 1);
			root->right = rebuildTree(pos-inleft+preleft+1, preright, pos + 1, inright);
			return root;
		}
		
	}
private:
	vector<int> preorder, inorder;
	map<int, int> hashmap;
};
int main()
{}