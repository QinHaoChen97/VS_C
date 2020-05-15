/*
解法参考
https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
		if (root==NULL || root==p ||root==q) //出现了要找的节点，直接返回
		{
			return root;
		}
		//后序遍历，因为上面找到后直接返回，所以实际上不是真正的后序遍历
		TreeNode* left=lowestCommonAncestor(root->left, p, q);
		TreeNode* right=lowestCommonAncestor(root->right, p, q);
		if (left==NULL)//一边是空那么直接返回另一边，因为不管另一边是空或者有找到节点都不会造成影响
		{
			return right;
		}
		else if(right==NULL)
		{
			return left;
		}
		else//左右都非空，那么说明此时的节点是最近的祖先节点
		{
			return root;
		}
	}
};
int main()
{

}