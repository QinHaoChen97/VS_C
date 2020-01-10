/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

 示例:

 给定 1->2->3->4, 你应该返回 2->1->4->3.

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		else
		{
			ListNode* prenode = head;//原来每一对节点的第一个节点，交换之后刚好变为上一对节点的第二个节点，用于链接下一对节点交换后的节点
			ListNode* nownode = head->next;//原来每对节点的第二个节点
			ListNode* nextnode = NULL;//下一对节点的第一个节点（如果有的话）
			ListNode* lastpairnode = NULL;//上一对节点的第二个节点
			if (nownode != NULL)
			{
				nextnode = nownode->next;
			}
			//第一对节点互换位置的话会改变头节点的位置，所以先处理
			nownode->next = prenode;
			prenode->next = nextnode;
			head = nownode;
			//之后处理后序的节点
			while (1)
			{
				if (nextnode != NULL && nextnode->next != NULL)
				{
					lastpairnode = prenode;//上一对节点的第二个节点
					prenode = nextnode;//当前这对节点的第一个节点
					nownode = nextnode->next;//当前这对节点的第二个节点
					nextnode = nownode->next;//下一对节点的第一个节点
					//分配好节点之后交换位置
					nownode->next = prenode;
					prenode->next = nextnode;
					lastpairnode->next = nownode;
				}
				else//如果没有下一对节点或者下一对节点中只有一个节点
				{
					return head;
				}
			}
		}
	}
};