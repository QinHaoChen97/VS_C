/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* prehead = new ListNode(-1);//前置节点
		prehead->next = head;
		stack<ListNode*> Node;//使用栈进行翻转
		ListNode* tail = prehead;//用于存放上一组的尾节点
		ListNode* cur = head;//当前节点
		ListNode* nexthead = NULL;//下一组的头节点
		int number = 0;//用于记录栈中需要翻转的个数
		while (cur)
		{
				Node.push(cur);
				cur = cur->next;
				number++;
				if (number==k)//到达翻转个数
				{		
					nexthead = cur;
					tail->next = Node.top();//将上一组的尾节点连接到当前组反转后的头节点
					while (--number)//将元素推出直至栈空，并将这部分链表元素反转
					{
						ListNode* TopNode = Node.top();
						Node.pop();
						TopNode->next = Node.top();//因为栈空不可以使用top()，所以这里的循环用number--
					}
					//此时栈中还剩下尾部元素
					tail = Node.top();
					tail->next = nexthead;
					Node.pop();
					//栈空，该部分反转完成
				}
		}
		head = prehead->next;
		delete prehead;
		prehead = NULL;
		return head;
	}
};