/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
    1->3->4,
	  2->6
	  ]
	  输出: 1->1->2->3->4->4->5->6

	  来源：力扣（LeetCode）
	  链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
	  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int length = lists.size();
		for (int i = 0; i < length; i++)//先对空节点进行操作，这些节点是没有用的
		{
			if (lists[i] == NULL)
			{
				lists.erase(lists.begin() + i);
				i--;//因为删除了当前的元素所以下一个元素的位置顶替到了当前位置
				length--;
			}
		}
		if (length==0)
		{
			return NULL;
		}
		else if(length==1)
		{
			return lists[0];
		}
		else//lists.size()>1,且此时所有的链表都不为空链表
		{
			ListNode* prehead = new ListNode(-1);//头节点
			ListNode* nownode = prehead;
			int minnode=0;
			while (length!=1)//当vector中只剩一个元素时那么只需要把该及后面剩下的链表排列上即可
			{
				minnode = 0;
				for (int i = 1; i < length; i++)//扫描一次（感觉这样有点暴力算法，最后可能会超时，可以考虑建立一个vector来保存当前的排序，之后只需要和当前的排序比较即可）
				{
					if (lists[minnode]->val>lists[i]->val)
					{
						minnode = i;
					}
				}
				//比较完一次便插入一次
				nownode->next = lists[minnode];
				nownode = nownode->next;
				//判断该链表是否已到达尾部
				if (lists[minnode]->next == NULL)
				{
					lists.erase(lists.begin() + minnode);
					length--;
				}
				else
				{
					lists[minnode]=lists[minnode]->next;
				}
			}
			//只剩下一个节点了
			nownode->next = lists[0];
			nownode = prehead->next;
			delete prehead;
			prehead = NULL;
			return nownode;
		}
	}
};
int main()
{}

/*
使用优先队列对方法的改进

class Solution {
public:
struct cmp{bool operator()(ListNode* l1, ListNode* l2){return l1->val > l2->val;}};  //伪函数，因为ListNode没有自带比较功能
ListNode* mergeKLists(vector<ListNode*>& lists){
ListNode* phead = new ListNode(0); ListNode* p = phead;
if(lists.size() == 0) return nullptr;
priority_queue<ListNode*, vector<ListNode*>, cmp> MinHeap;
for(int i = 0;i < lists.size();i++) if(lists[i] != nullptr)MinHeap.push(lists[i]);
while(!MinHeap.empty()){
p->next = MinHeap.top();p = p->next;
if(MinHeap.top()->next != nullptr) MinHeap.push(MinHeap.top()->next);MinHeap.pop();  //这里可以这样做是因为链表是有序的，所以push进去之后不会改变原先的最大优先权
}
return phead->next;
}
};

作者：tai-er-si-can-xing
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/cyou-xian-dui-lie-he-bing-by-tai-er-si-can-xing/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/