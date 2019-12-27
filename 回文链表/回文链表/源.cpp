/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head==NULL)  //空链表也视为回文链表
		{
			return true;
		}
		string front = "", rear = "";  //分别用两个字符串存储向前扫描的数字和向后扫描的数字，若两者相等说明链表是回文链表
		getstring(head, front, rear);
		if (front==rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void getstring(ListNode* head, string &front, string &rear)
	{
		if (head!=NULL)
		{
			front += head->val; //向前扫描字符串
			getstring(head->next, front, rear);
		}
		else  //这一步防止在尾部空节点时运行rear+=head->val；
		{
			return;
		}
		//递归回溯
		rear += head->val;
	}
};