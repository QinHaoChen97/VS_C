/*
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 //使用快慢指针，如果有环那么快指针必然会追上慢指针，如果没有环那么快指针必然会先到达NULL
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head==NULL)
		{
			return false;
		}
		ListNode *Fastpoint = head; //快指针
		ListNode *Slowpoint = head; //慢指针
		while (Fastpoint->next != NULL && Fastpoint->next->next != NULL)
		{
			Fastpoint = Fastpoint->next->next;
			Slowpoint = Slowpoint->next;//循环条件中已经包含了Slowpoint->next是不是等于NULL
			if (Fastpoint==Slowpoint)
			{
				return true;
			}
		}
		return false;//节点出现NULL才会执行这一步

	}
};