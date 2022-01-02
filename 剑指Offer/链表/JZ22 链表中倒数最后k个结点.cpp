//https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9?tpId=13&tqId=1377477&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k)
    {
        // write code here
        //为了实现O(1)空间复杂度
        //用一遍遍历得到链表的长度length，第二遍找到倒数的第k个元素，即length-k+1个元素，如果length<k，返回空节点
        auto current_node=pHead;
        int length=0;
        while (current_node!=nullptr)
        {
            length++;
            current_node=current_node->next;
        }
        if (k>length)
        {
            return nullptr;
        }
        else
        {
            current_node=pHead;
            int n=length-k+1;
            for (int i = n-1; i>0 ; i--) //当前节点便是第一个，所以从n-1开始
            {
                current_node=current_node->next;
            }
            return current_node;
            
        }
        
        
        
    }
};
//快慢指针的写法
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        
        ListNode* fast=pHead;
        for (int i = k; i >0; i--) //快指针先走k步，这样和慢指针就有k个身位的差距
        {
            if (fast!=nullptr)
            {
                fast=fast->next;
            }
            else
            {
                return nullptr;
            }
        }
        ListNode* slow=pHead;
        while (fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};