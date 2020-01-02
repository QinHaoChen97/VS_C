/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1==NULL)
		{
			return l2;
		}
		else if (l2==NULL)
		{
			return l1;
		}
		else
		{
			int flag = 0;//进位
			int sum = 0;//暂存当前两数相加的结果
			ListNode *head1 = l1, *head2 = l2;
			ListNode* newlisthead = new ListNode(-1);
			ListNode* newlist = newlisthead;
			while (head1!=NULL && head2!=NULL) //两个链表都未到达链表尾
			{
				sum = head1->val + head2->val+flag;
				ListNode* Node = new ListNode(sum % 10);
				flag = sum / 10; //更新进位
				newlist->next = Node;
				newlist = newlist->next;
				head1 = head1->next;
				head2 = head2->next;
			}
			//有链表到达链表结尾
			//若是刚好这一节点是9+1（flag），则还可能再进位,同理后序的节点也一样
			if (head1==NULL)//如果可以在原来的链表上修改的话此处可以有改进，一旦发现没有进位的时候直接将原链表链入，因为最大就是9不会再有进位了
			{
				while (head2!=NULL)
				{
					sum = head2->val + flag;
					ListNode* Node = new ListNode(sum % 10);
					flag = sum / 10;
					newlist->next = Node;
					newlist = newlist->next;
					head2 = head2->next;
				}
			}
			else//说明是head2==NULL
			{
				while (head1!=NULL)  
				{
					sum = head1->val + flag;
					ListNode* Node = new ListNode(sum % 10);
					flag = sum / 10;
					newlist->next = Node;
					newlist = newlist->next;
					head1 = head1->next;

				}
			}
			//链表链接完
			if (flag==1) //即此时需要多加一位
			{
				ListNode* Node = new ListNode(1);
				newlist->next = Node;
			}
			newlist = newlisthead->next;
			delete newlisthead;
			newlisthead = NULL;
			return newlist;
		}
	}
};