
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};
//快慢指针，快的每次走两步，慢的走一步
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        auto fast_p=pHead;
        auto slow_p=pHead;
        while (fast_p!=nullptr && fast_p->next!=nullptr)
        {
            fast_p=fast_p->next->next;
            slow_p=slow_p->next;
            if (fast_p==slow_p) // 找到环，根据环的性质，让slow_p从链表头重新开始走，fast_p的前进速度变为1,当再次相等时的节点即为环表的头节点
            //https://blog.nowcoder.net/n/9d3ffa4b004e43d1aff512141d0d7dac?f=comment
            //思路可以看这个，但是它的解法看起来很奇怪，不用看
            {
                slow_p=pHead;
                while (slow_p!=fast_p)
                {
                    slow_p=slow_p->next;
                    fast_p=fast_p->next;
                }
                return slow_p;
            }
            
        }
        //fast_p==nullptr或者fast_p->next==nullptr，说明没有环
        return nullptr;
        
    }
};