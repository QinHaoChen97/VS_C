/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1==NULL)
		{
			return l2;
		}
		else if(l2==NULL)
		{
			return l1;
		}
		else
		{
			ListNode* newlisthead = new ListNode(-1);
			ListNode* newlist = newlisthead;
			ListNode *head1 = l1, *head2 = l2;
			while (head1!=NULL && head2!=NULL) //两者都未到达到节点尾
			{
				//新链表链接上小的节点，被链接的点指向下一节点
				if (head1->val<=head2->val) 
				{
					newlist->next = head1; 
					newlist = newlist->next;
					head1 = head1->next;
				}
				else
				{
					newlist->next = head2;
					newlist = newlist->next;
					head2 = head2->next;
				}
			}
			//有链表到达尾部了,将未达到尾部的链表链接到新链表尾部
			head1 == NULL ? newlist->next = head2 : newlist->next = head1;
			newlist = newlisthead->next;
			delete newlisthead;
			return newlist;
		}
	}
};
int main()
{}