/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
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
//由于是排序链表，用一个数字保存当前的节点的val,下一数字若相同则将其删除
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head==NULL)
		{
			return head;
		}
		else
		{	
			ListNode* prehead = new ListNode(-1);//前置节点，因为头节点也可能被删除
			prehead->next = head;
			int lastval;//用于保存需要被删除节点的值
			ListNode* NowNode = head;
			ListNode* NextNode = NULL;//用于存储需要删除节点的下一节点
			ListNode* LastNode = prehead;//用于存储需要删除节点的上一节点
			while (1)
			{
				if (NowNode!=NULL && NowNode->next!=NULL)//line43
				{
					if (NowNode->val==NowNode->next->val)//是否有重复节点？
					{
						//是的话,先删除这两个重复节点，NowNode指向这两个节点后的节点
						lastval = NowNode->val;
						NextNode = NowNode->next->next;
						delete NowNode->next;
						delete NowNode;
						LastNode->next = NextNode;
						NowNode = NextNode;
						while (1)//查找后续是否还有重复节点
						{
							if (NowNode!=NULL)
							{
								if (NowNode->val==lastval)//那么删除该重复节点
								{
									NextNode = NowNode->next;
									delete NowNode;
									LastNode->next = NextNode;
									NowNode = NextNode;
								}
								else//不再是重复节点了
								{
									break;
								}
							}
							else
							{
								break;//回到line43，进行回到line66
							}
						}
					}
					else//当前节点和下一节点不是重复节点
					{
						LastNode = NowNode;
						NowNode = NowNode->next;
					}
				}
				else//line66
				{
					head = prehead->next;
					delete prehead;
					prehead = NULL;
					return head;
				}
			}
		}
	}
};