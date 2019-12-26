/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		//排除只有一个或两个节点的情况
		if (head==NULL)
		{
			return NULL;
		}
		if (head->next==NULL)
		{
			return head;
		}
		if (head->next->next==NULL)
		{
			return head;
		}
		ListNode* evennodehead = new ListNode(-1);	//作为偶数节点的头
		evennodehead->next = head->next;
		ListNode* evennodetail = evennodehead->next;//偶数节点的尾，初始时是一样的
		ListNode* oddnodetail = head; //奇数节点的尾
		ListNode* rightnode = head->next->next;  //从第三个节点开始
		while (rightnode!=NULL)
		{
			if (rightnode->next!=NULL) //接下来的两个节点都不为空节点
			{
				//链接偶数节点
				evennodetail->next = rightnode->next;  
				evennodetail = evennodetail->next;
				//链接奇数节点
				oddnodetail->next = rightnode;
				oddnodetail = oddnodetail->next;
				rightnode = rightnode->next->next;
			}
			else//接下来只有一个奇数节点
			{
				oddnodetail->next = rightnode;
				oddnodetail = oddnodetail->next;
				rightnode = rightnode->next; //跳出whlie
			}
		}
		//因为偶节点在后方，需要在偶节点尾部链接一个NULL
		evennodetail->next = NULL;
		//拼接
		oddnodetail->next = evennodehead->next;
		return head;
	}
};