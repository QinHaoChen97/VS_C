#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		i = 0;
		ListNode *prehead = new ListNode(0);
		prehead->next = head;//����ڵ���Ϊ�˷�ֹɾ���Ľڵ�Ϊͷ�ڵ�����������������ڵ㲻���ɾ��β���Ľڵ����Ӱ��
		finddel_last_node(prehead, n + 1);//ע�⴫��Ĳ���
		i = 0;
		return prehead->next;  //����preheadָ��ͷ�ڵ㣬���������Ƿ�ɾ����Ϊhead��prehead->next��������ɾ�����ͷ�ڵ�

	}
	void finddel_last_node(ListNode* head, int n_1)  //�ҵ�������N+1���ڵ�,��Ϊ������һ��ȫ�ֱ���������������void�������int�ͣ���ô���Բ�Ҫ���ȫ�ֱ���
	{
		ListNode* p = head;   //�����ǵ�ַ���Σ���������Ҫ�¹���һ����ʱ����
		if (p->next != NULL)
		{
			finddel_last_node(p->next, n_1);
		}
		i++;
		if (i == n_1)  //˵���ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
		{
			p->next = p->next->next;  //��ʱpΪ������n+1���ڵ�
		}
		return;
	}
private:
	int i;
};
//������java�Ĵ��룬��ûʲô���
/*
ListNode* removeNthFromEnd(ListNode* head, int n) {

int sum = getCurrentIndexFromLast(head,n);
if(sum == n){
return head->next;
}else{
return head;
}
}


int getCurrentIndexFromLast(ListNode* head,int n){  //��������÷���ֵ������Բ���Ҫ˽�б���i
if(head->next == 0){  //�ҵ�����β��
return 1;
}else{
int sum = getCurrentIndexFromLast(head->next,n);
if(sum == n){  //�жϵ�ǰ�ڵ��Ƿ���Ҫɾ���ڵ��ǰһ�ڵ�
ListNode * node =  head->next;
head->next = node->next;
}
return sum + 1;
}

}

���ߣ�moonbirds
���ӣ�https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/di-gui-cha-xun-sheng-yu-chang-du-que-ding-wei-zhi-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/