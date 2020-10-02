#include<iostream>
#include<map>
#include<stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		length = 0;
		length_hashmap = 0;
		RecurTreeNode(root);
	}

	/** @return the next smallest number */
	int next() {
		if (length_hashmap==length)
		{
			return 0;
		}
		else
		{
			return TreeMap[++length_hashmap];
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (length_hashmap>=length)
		{
			return false;
		}
		return true;
	}
	/* �������Ĺ�ϣ��*/
	void RecurTreeNode(TreeNode* root)
	{
		if (root==NULL)
		{
			return;
		}
		RecurTreeNode(root->left);
		TreeMap[++length] = root->val;
		RecurTreeNode(root->right);
		return;
	}
private:
	map<int, int> TreeMap;
	int length;//�ڵ����==��ϣ����
	int length_hashmap;
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

//����ջ����
class BSTIterator1 {
public:

	stack<TreeNode*> st;

	BSTIterator1(TreeNode* root) {
		TreeNode* cur = root;
		while (cur) {
			st.push(cur);
			cur = cur->left;
		}
	};

	/** @return the next smallest number */
	int next() {
		TreeNode* node = st.top();
		st.pop();
		int ans = node->val;
		node = node->right;
		while (node) {
			st.push(node);
			node = node->left;
		}
		return ans;

	};

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return st.size();
	}
};

/*
���ߣ�wangdh15
���ӣ�https ://leetcode-cn.com/problems/binary-search-tree-iterator/solution/zhan-mo-ni-zhong-xu-bian-li-by-acw_wangdh15/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
