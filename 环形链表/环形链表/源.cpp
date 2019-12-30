/*
����һ�������ж��������Ƿ��л���

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���
ʾ�� 1��

���룺head = [3,2,0,-4], pos = 1
�����true
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<iostream>
using namespace std;
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 //ʹ�ÿ���ָ�룬����л���ô��ָ���Ȼ��׷����ָ�룬���û�л���ô��ָ���Ȼ���ȵ���NULL
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head==NULL)
		{
			return false;
		}
		ListNode *Fastpoint = head; //��ָ��
		ListNode *Slowpoint = head; //��ָ��
		while (Fastpoint->next != NULL && Fastpoint->next->next != NULL)
		{
			Fastpoint = Fastpoint->next->next;
			Slowpoint = Slowpoint->next;//ѭ���������Ѿ�������Slowpoint->next�ǲ��ǵ���NULL
			if (Fastpoint==Slowpoint)
			{
				return true;
			}
		}
		return false;//�ڵ����NULL�Ż�ִ����һ��

	}
};