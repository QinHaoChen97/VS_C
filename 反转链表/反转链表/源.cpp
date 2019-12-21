#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head==NULL)
		{
			return NULL;
		}
		ListNode* p=resverse(head);
		head->next = NULL;
		return p;
	}
	ListNode* resverse(ListNode* head) 
	{
		if (head->next==NULL)
		{
			return head;  //���ҵ�������һ���ڵ��ִ��,ͬʱҲ��ֹ��ֻ��
		}
		ListNode* p=resverse(head->next);  
		//ִ�е���һ��˵���Ѿ����˵����ڶ����ڵ���
		head->next->next = head;
		return p;
	}
};
int main()
{

}