struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
//思路十分简单，用一个哨兵节点作为头部，然后不断将两个链表的头节点进行比较，较小的节点便插入到新构建的链表中，直到有一个链表
//已经插入了自身的所有节点，则将仍有剩余节点的链表直接插入到新构建的链表的尾部
#include<memory>
using std::shared_ptr;
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        auto prev_node=std::make_shared<ListNode>(0);
        ListNode* current_node=prev_node.get(); // 不能delete current_node，要把内存交给share_ptr去管理
        while (pHead1!=nullptr && pHead2!=nullptr)
        {
            if (pHead1->val<=pHead2->val)
            {
                current_node->next=pHead1;
                pHead1=pHead1->next;
            }
            else
            {
                current_node->next=pHead2;
                pHead2=pHead2->next;
            }
            current_node=current_node->next;
        }
        current_node->next=pHead1==nullptr?pHead2:pHead1;
        return prev_node->next;
        

    }
};