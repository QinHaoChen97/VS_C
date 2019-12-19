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
		prehead->next = head;//这个节点是为了防止删除的节点为头节点的情况，且增加这个节点不会对删除尾部的节点造成影响
		finddel_last_node(prehead, n + 1);//注意传入的参数
		i = 0;
		return prehead->next;  //由于prehead指向头节点，所以无论是否删除的为head，prehead->next都代表着删除后的头节点

	}
	void finddel_last_node(ListNode* head, int n_1)  //找到倒数第N+1个节点,因为设置了一个全局变量，所以这里用void，如果用int型，那么可以不要这个全局变量
	{
		ListNode* p = head;   //由于是地址传参，所以这里要新构造一个临时变量
		if (p->next != NULL)
		{
			finddel_last_node(p->next, n_1);
		}
		i++;
		if (i == n_1)  //说明找到要删除节点的前一个节点
		{
			p->next = p->next->next;  //此时p为倒数第n+1个节点
		}
		return;
	}
private:
	int i;
};
//下面是java的代码，但没什么差别
/*
ListNode* removeNthFromEnd(ListNode* head, int n) {

int sum = getCurrentIndexFromLast(head,n);
if(sum == n){
return head->next;
}else{
return head;
}
}


int getCurrentIndexFromLast(ListNode* head,int n){  //巧妙的利用返回值，便可以不需要私有变量i
if(head->next == 0){  //找到链表尾部
return 1;
}else{
int sum = getCurrentIndexFromLast(head->next,n);
if(sum == n){  //判断当前节点是否是要删除节点的前一节点
ListNode * node =  head->next;
head->next = node->next;
}
return sum + 1;
}

}

作者：moonbirds
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/di-gui-cha-xun-sheng-yu-chang-du-que-ding-wei-zhi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/