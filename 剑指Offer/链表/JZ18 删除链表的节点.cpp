// https://www.nowcoder.com/practice/f9f78ca89ad643c99701a7142bd59f5d?tpId=13&tqId=2273171&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param val int整型
     * @return ListNode类
     */
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode* prehead=new ListNode(-1);
        prehead->next=head;
        auto current_node=prehead;
        while (current_node->next!=nullptr)
        {
            if (current_node->next->val==val)
            {
                current_node->next=current_node->next->next;
                head=prehead->next;
                delete prehead;
                return head;
            }
            current_node=current_node->next;
        }
        return head; //为了通过编译加的
    }
};