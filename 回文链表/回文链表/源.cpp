/*
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
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
		if (head==NULL)  //������Ҳ��Ϊ��������
		{
			return true;
		}
		string front = "", rear = "";  //�ֱ��������ַ����洢��ǰɨ������ֺ����ɨ������֣����������˵�������ǻ�������
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
			front += head->val; //��ǰɨ���ַ���
			getstring(head->next, front, rear);
		}
		else  //��һ����ֹ��β���սڵ�ʱ����rear+=head->val��
		{
			return;
		}
		//�ݹ����
		rear += head->val;
	}
};