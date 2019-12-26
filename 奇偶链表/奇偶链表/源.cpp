/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�

�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:

����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:

����: 2->1->3->5->6->4->7->NULL
���: 2->3->6->7->1->5->4->NULL
˵��:

Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/odd-even-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
		//�ų�ֻ��һ���������ڵ�����
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
		ListNode* evennodehead = new ListNode(-1);	//��Ϊż���ڵ��ͷ
		evennodehead->next = head->next;
		ListNode* evennodetail = evennodehead->next;//ż���ڵ��β����ʼʱ��һ����
		ListNode* oddnodetail = head; //�����ڵ��β
		ListNode* rightnode = head->next->next;  //�ӵ������ڵ㿪ʼ
		while (rightnode!=NULL)
		{
			if (rightnode->next!=NULL) //�������������ڵ㶼��Ϊ�սڵ�
			{
				//����ż���ڵ�
				evennodetail->next = rightnode->next;  
				evennodetail = evennodetail->next;
				//���������ڵ�
				oddnodetail->next = rightnode;
				oddnodetail = oddnodetail->next;
				rightnode = rightnode->next->next;
			}
			else//������ֻ��һ�������ڵ�
			{
				oddnodetail->next = rightnode;
				oddnodetail = oddnodetail->next;
				rightnode = rightnode->next; //����whlie
			}
		}
		//��Ϊż�ڵ��ں󷽣���Ҫ��ż�ڵ�β������һ��NULL
		evennodetail->next = NULL;
		//ƴ��
		oddnodetail->next = evennodehead->next;
		return head;
	}
};