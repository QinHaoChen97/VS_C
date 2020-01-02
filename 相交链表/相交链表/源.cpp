/*
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
*/
#include<iostream>
using namespace std;
struct ListNode
{
	ListNode* next;
	int val;
	ListNode(int x) :next(NULL), val(x) {};
};
/*
ʱ�临�Ӷ�O��A+B��
�ռ临�Ӷ�O(1)
��������ָ�� pApA �� pBpB���ֱ��ʼ��Ϊ���� A �� B ��ͷ��㡣Ȼ��������������������
�� pApA ���������β��ʱ�������ض�λ������ B ��ͷ��� (��û������������ B); ���Ƶģ��� pBpB ���������β��ʱ�������ض�λ������ A ��ͷ��㡣
����ĳһʱ�� pApA �� pBpB �������� pApA/pBpB Ϊ�ཻ��㡣

ԭ�������������ٶ���ͬ����ô��ͬʱ�����߹���·������ͬ�ģ����������������ཻ�ģ����ȷֱ�ΪA,B
��ôA+B=B+A
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA==NULL || headB==NULL )
		{
			return NULL;
		}
		else
		{
			ListNode *pathA = headA, *pathB = headB;
			bool aonceend = false,bonceend=false;//��־λ����ʾpathA��pathB�Ƿ��һ���ߵ��յ�
			while (1)
			{
				//Ҫ��ȷ��ʹ���ཻ������Ҳ��ͬʱ�����յ�NULL����Ϊ�ߵ�·������ͬ��
				if (pathA == pathB)  //������ཻ��������߶�����NULL
				{
					return  pathA;
				}
				if (pathA->next==NULL && aonceend==false)
				{
					pathA = headB;
					aonceend = true;
				}
				else
				{
					pathA=pathA->next;
				}
				if (pathB->next==NULL && bonceend==false)
				{
					pathB = headA;
					bonceend = true;
				}
				else
				{
					pathB = pathB->next;
				}
			}
		}
	}
};