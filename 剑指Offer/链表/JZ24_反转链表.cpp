
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};
#include<stack>
using std::stack;
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead==nullptr)
        {
            return pHead;
        }
        
        auto node=pHead;
        stack<ListNode*> sta;
        while (node!=nullptr)
        {
            sta.emplace(node);
            node=node->next;
        }
        pHead=sta.top();
        node=sta.top();
        sta.pop();
        while (!sta.empty())
        {
            node->next=sta.top();
            sta.pop();
            node=node->next;
        }
        node->next=nullptr; //最后一个节点的尾部应该是一个空节点
        return pHead;
        
        
    }
   
};
//解法2 O(1)的空间复杂度
class Solution2 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead==nullptr)
        {
            return pHead;
        }
        auto next_node = pHead->next;
        ListNode* prev_node=nullptr; // 已反转序列的头节点
        ListNode* current_node=pHead; //未翻转部分的头节点
        while (current_node!=nullptr)
        {
            current_node->next=prev_node; //当前节点的下一个节点变成已经翻转过的链表部分的头节点
            prev_node=current_node; // 更新已翻转部分的头节点
            current_node=next_node; 
            next_node=current_node->next;
        }

        return prev_node;
        
    }
};