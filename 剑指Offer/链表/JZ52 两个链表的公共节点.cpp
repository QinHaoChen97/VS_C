struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr    ) {
	}
};
//https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=23257&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//巧妙的在逻辑上将两个链表结合在一起
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        auto node1=pHead1,node2=pHead2;
        while (node1!=node2)
        {
            node1=node1?node1->next:pHead2;  //当遍历完pHead1的节点时想象pHead2的节点接在其后面，下面的处理同理
            node2=node2?node2->next:pHead1;
        }
        return node1; //如果此时node1是空节点则证明两个节点不相交，如果不是则此时指向的是第一个相交的节点
        
        
    }
};