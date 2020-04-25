/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/
#include<iostream>
#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (root==NULL)
		{
			return root;
		}
		queue<Node*> queue1, queue2;
		queue1.push(root);
		while (!queue1.empty() || !queue2.empty())//如果有一个队列非空
		{
			while(!queue1.empty())
			{
				Node* node = queue1.front();
				queue1.pop();
				if (node->left!=NULL)
				{
					queue2.push(node->left);
				}
				if (node->right!=NULL)
				{
					queue2.push(node->right);
				}
				if (queue1.empty())
				{
					break;
				}
				else
				{
					node->next = queue1.front();//指向右侧节点
				}
			}
			while (!queue2.empty())
			{
				Node* node = queue2.front();
				queue2.pop();
				if (node->left != NULL)
				{
					queue1.push(node->left);
				}
				if (node->right != NULL)
				{
					queue1.push(node->right);
				}
				if (queue2.empty())
				{
					break;
				}
				else
				{
					node->next = queue2.front();//指向右侧节点
				}
			}
		}
		return root;
	}
};