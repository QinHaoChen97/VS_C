#include<iostream>
using namespace std;
/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {	
		if (head==NULL)
		{
			return NULL;
		}
		if (m==n) //没有发生翻转
		{
			return head;
		}
		//构造一个指针指向头节点,prehead的序号为0
		ListNode* prehead = new ListNode(0);
		prehead->next = head;
		int i = 0;
		ListNode* invertpro = prehead; //被翻转部分的前一节点
		ListNode* invertnextnode = NULL;  //被翻转部分的后一节点
		while (i!=m-1)
		{
			invertpro = invertpro->next;
			i++;
		}
		i++;
		ListNode* headtotail = invertpro->next;  //指向要翻转部分的起点，也是翻转后的尾部
		ListNode* tailtohead = NULL; //指向翻转后的头部
		invert(headtotail, i, n, invertnextnode,tailtohead);
		//翻转后将翻转部分与未翻转部分拼接
		invertpro->next = tailtohead;
		headtotail->next = invertnextnode;

		return prehead->next;
		
	}
	void invert(ListNode* head, int &m,const int n,ListNode* &invertnextnode,ListNode* &tailtohead)  //返回被翻转部分的后一节点
	{
		m++;
		if (m == n) //说明此时指向倒数第二个节点，开始翻转
		{
			invertnextnode = head->next->next;   
			tailtohead = head->next;  //翻转后的头部
			head->next->next = head;
			m--;
			return;
		}
		else
		{
			invert(head->next, m, n, invertnextnode,tailtohead);
		}
		//递归结束开始回退
		head->next->next = head;//翻转
		return;
	}
};
int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	for (int i = 2; i < 6; i++)
	{
		p->next = new ListNode(i);
		p = p->next;
	}
	Solution a;
	a.reverseBetween(head, 2, 4);
	cin.get();
}