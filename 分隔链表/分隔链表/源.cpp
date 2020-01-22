/*
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ��:

����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->4->3->5

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head==NULL)
		{
			return NULL;
		}
		else
		{
			ListNode* NowNode = head;
			ListNode* preHead = new ListNode(-1);//���ڱ���С��x�Ľڵ�
			ListNode* aftHead = new ListNode(-1);//���ڱ�����ڵ���x�Ľڵ�
			ListNode* preNode = preHead;
			ListNode* aftNode = aftHead;
			while (NowNode!=NULL)
			{
				if (NowNode->val<x)
				{
					preNode->next = NowNode;
					preNode=preNode->next;
				}
				else
				{
					aftNode->next = NowNode;
					aftNode = aftNode->next;
				}
				NowNode = NowNode->next;
			}
			//������ָ���Ϻ�
			aftNode->next = NULL;//ע����һ������Ҫ������β���Ľڵ㲻һ��ָ��NULL���ᵼ�����ɻ����������²��԰�������
			preNode->next = aftHead->next;
			delete aftHead;
			aftHead = NULL;
			head = preHead->next;
			delete preHead;
			preHead = NULL;
			return head;
		}
	}
};
int main() {
	int a[6] = { 1,4,6,7,2 };
	ListNode* head = new ListNode(-1);
	ListNode* NowNode = head;
	for (int i = 0; i < 5; i++)
	{
		NowNode->next = new ListNode(a[i]);
		NowNode = NowNode->next;
	}
	Solution test;
	test.partition(head->next,3);
	cin.get();
}