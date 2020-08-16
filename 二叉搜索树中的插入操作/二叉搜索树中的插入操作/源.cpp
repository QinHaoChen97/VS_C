/*二叉搜索树中的插入操作*/
#include<iostream>
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};
class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root==NULL)
		{
			root = new TreeNode(val);
			return root;
		}
		TreeNode* InsertNode = root;
		while (1)
		{
			if(InsertNode->val<val)
			{
				if (InsertNode->right==NULL)
				{
					InsertNode->right = new TreeNode(val);
					return root;
				}
				else
				{
					InsertNode = InsertNode->right;
				}
			}
			else
			{
				if (InsertNode->left == NULL)
				{
					InsertNode->left = new TreeNode(val);
					return root;
				}
				else
				{
					InsertNode = InsertNode->left;
				}
			}
		}
	}
};
int main()
{
	TreeNode* a = new TreeNode(4);
	a->right = new TreeNode(7);
	Solution b;
	b.insertIntoBST(a, 5);
	std::cin.get();
}