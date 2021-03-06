﻿/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head==NULL)
		{
			return NULL;
		}
		if (k<=0)
		{
			return head;
		}
		int length = 0;
		ListNode* nodehead=head;
		while (nodehead!=NULL)
		{
			length++;
			if (nodehead->next==NULL)
			{
				break;
			}
			nodehead=nodehead->next;
		}
		//此时nodehead在链表尾
		int x = k%length;
		//新表头便是倒数第x个节点也即第length-x个节点
		ListNode *newtail = head;
		//length-x-1即为新表尾
		for (int i = 0; i < length-x-1; i++)
		{
			newtail = newtail->next;//
		}
		nodehead->next = head;//将链表形成环
		head = newtail->next;
		newtail->next = NULL;
		return head;

	}
};
int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	p1->next = p2;
	Solution a;
	ListNode*head=a.rotateRight(p1,1);
	cin.get();
}