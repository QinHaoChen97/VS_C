/*
¶ş²æËÑË÷Ê÷ÖĞµÄËÑË÷
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
	TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode* NowNode = root;
		while (1)
		{
			if (NowNode==NULL)
			{
				return NULL;
			}
			else if(NowNode->val==val)
			{
				return NowNode;
			}
			else if(NowNode->val<val)
			{
				NowNode = NowNode->right;
			}
			else
			{
				NowNode = NowNode->left;
			}
		}
	}
};