/*
����һ��������������������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�

struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��

��ʼ״̬�£����� next ָ�붼������Ϊ NULL��
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
		while (!queue1.empty() || !queue2.empty())//�����һ�����зǿ�
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
					node->next = queue1.front();//ָ���Ҳ�ڵ�
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
					node->next = queue2.front();//ָ���Ҳ�ڵ�
				}
			}
		}
		return root;
	}
};