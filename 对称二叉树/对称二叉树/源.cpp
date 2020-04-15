/*
����һ����������������Ƿ��Ǿ���ԳƵġ�



���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

    1
   / \
  2    2
 / \  / \
3  4 4   3


����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode/
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :left(NULL), right(NULL), val(x) {};
};
class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if (root==NULL)
			{
				return false;
			}
			return symmetry(root->left, root->right);
		}
		void pushval(TreeNode* node, vector<int> &vec)//�������,�������ֻ�������ĸ�����ֵ��Ϊһ��һ�Ե�ʱ�����Ч,�������������ȱ�ݣ�����ͨ��ȫ���Ĳ��԰���
		{
			if (node==NULL)
			{
				vec.push_back(0);
				return;
			}
			else
			{
				pushval(node->left,vec);
			}
			vec.push_back(node->val);
			pushval(node->right,vec);
			return;
		}
		bool symmetry(TreeNode *nodeleft, TreeNode *noderight)//�ԳƷ���
		{
			if (nodeleft==NULL && noderight==NULL)//�ԳƵĵ㶼Ϊ�սڵ�
			{
				return true;
			}
			else if(nodeleft==NULL || noderight==NULL)//�ԳƵĵ���һ��Ϊ�սڵ�
			{
				return false;
			}
			//�ԳƵĵ㶼��Ϊ�սڵ㣬���Ȳ鿴val�Ƿ���ȣ������������µݹ飬ע���Ҫ�Գ��ж�
			return (nodeleft->val == noderight->val) && symmetry(nodeleft->left, noderight->right) && symmetry(nodeleft->right, noderight->left);
		}

};
int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	Solution a;
	bool b = true;
	b=a.isSymmetric(root);
	cin.get();
}