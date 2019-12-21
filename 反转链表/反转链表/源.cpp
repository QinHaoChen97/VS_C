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
			return head;  //当找到倒数第一个节点会执行,同时也防止了只有
		}
		ListNode* p=resverse(head->next);  
		//执行到这一步说明已经到了倒数第二个节点了
		head->next->next = head;
		return p;
	}
};
int main()
{

}