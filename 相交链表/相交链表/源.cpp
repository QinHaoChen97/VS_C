/*
编写一个程序，找到两个单链表相交的起始节点。
*/
#include<iostream>
using namespace std;
struct ListNode
{
	ListNode* next;
	int val;
	ListNode(int x) :next(NULL), val(x) {};
};
/*
时间复杂度O（A+B）
空间复杂度O(1)
创建两个指针 pApA 和 pBpB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
当 pApA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pBpB 到达链表的尾部时，将它重定位到链表 A 的头结点。
若在某一时刻 pApA 和 pBpB 相遇，则 pApA/pBpB 为相交结点。

原理上是利用了速度相同，那么相同时间内走过的路程是相同的，若是两个链表是相交的，长度分别为A,B
那么A+B=B+A
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA==NULL || headB==NULL )
		{
			return NULL;
		}
		else
		{
			ListNode *pathA = headA, *pathB = headB;
			bool aonceend = false,bonceend=false;//标志位，表示pathA和pathB是否第一次走到终点
			while (1)
			{
				//要明确即使不相交，两者也会同时到达终点NULL，因为走的路径是相同的
				if (pathA == pathB)  //如果不相交，最后两者都等于NULL
				{
					return  pathA;
				}
				if (pathA->next==NULL && aonceend==false)
				{
					pathA = headB;
					aonceend = true;
				}
				else
				{
					pathA=pathA->next;
				}
				if (pathB->next==NULL && bonceend==false)
				{
					pathB = headA;
					bonceend = true;
				}
				else
				{
					pathB = pathB->next;
				}
			}
		}
	}
};