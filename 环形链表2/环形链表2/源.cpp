/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

 示例 1：

 输入：head = [3,2,0,-4], pos = 1
 输出：tail connects to node index 1
 解释：链表中有一个环，其尾部连接到第二个节点。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
//使用哈希表存储访问过的节点，当第一次出现重复出现的节点时说明其便是环的入口
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head==NULL)
		{
			return NULL;
		}
		map<ListNode*, int> a;
		ListNode* node = head;
		while (node!=NULL)
		{
			if (a.count(node))//如果出现了相同的节点
			{
				return node;
			}
			a[node] = node->val; //将节点放入map中
			node = node->next;
		}
		return NULL; //当能访问到空节点时，说明不存在环
	}
};

/*
另一种解法，双指针，O(1)空间
https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
这个题主的算数分析更加清楚
官方的在分析上不太严谨，对第二阶段默认一圈后就相遇了，下面的评论有加以纠正
*/