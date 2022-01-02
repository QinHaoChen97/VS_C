
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {

        ListNode* h=new ListNode(0);  // 1<=>val<=1000
        h->next=pHead;
        auto last_node=h,current_node=pHead; //last_end指示上一个不重复的节点，end指示当前重复区间的尾节点
        while (current_node!=nullptr && current_node->next!=nullptr) //当前节点不为空也需要判断，出现这种情况一般是输入为空间点或者删除区间后刚好指向尾节点。
        {
            if (current_node->val != current_node->next->val)
            {
                last_node=current_node;
                current_node=current_node->next;
            }
            else //出现重复区间，一直找到该重复区间的尾节点
            {
                int re_val=current_node->val;
                current_node=current_node->next; //指向重复区间的第二个节点
                while (current_node->next!=nullptr && current_node->next->val==re_val)//找到该重复区间的尾节点
                {
                    current_node=current_node->next;
                }
                //删除重复区间，但这里没有释放内存，最好还是要释放内存
                last_node->next=current_node->next;
                current_node=current_node->next;//当前节点指向未扫描区间的头节点
            }
            
            
        }
        pHead=h->next;
        delete h;
        return pHead;
    }
};