/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head==NULL)
		{
			return NULL;
		}
		else
		{
			ListNode* NowNode = head;
			ListNode* preHead = new ListNode(-1);//用于保存小于x的节点
			ListNode* aftHead = new ListNode(-1);//用于保存大于等于x的节点
			ListNode* preNode = preHead;
			ListNode* aftNode = aftHead;
			while (NowNode!=NULL)
			{
				if (NowNode->val<x)
				{
					preNode->next = NowNode;
					preNode=preNode->next;
				}
				else
				{
					aftNode->next = NowNode;
					aftNode = aftNode->next;
				}
				NowNode = NowNode->next;
			}
			//将链表分割完毕后
			aftNode->next = NULL;//注意这一步很重要，否则尾部的节点不一定指向NULL，会导致生成环形链表，导致测试案例出错。
			preNode->next = aftHead->next;
			delete aftHead;
			aftHead = NULL;
			head = preHead->next;
			delete preHead;
			preHead = NULL;
			return head;
		}
	}
};
int main() {
	int a[6] = { 1,4,6,7,2 };
	ListNode* head = new ListNode(-1);
	ListNode* NowNode = head;
	for (int i = 0; i < 5; i++)
	{
		NowNode->next = new ListNode(a[i]);
		NowNode = NowNode->next;
	}
	Solution test;
	test.partition(head->next,3);
	cin.get();
}