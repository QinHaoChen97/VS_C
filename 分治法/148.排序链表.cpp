/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/*
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        int length = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            length++;
            curr = curr->next;
        }
        ListNode *headfind = new ListNode(0, head);
        for (int sub = 1; sub <= length; sub = sub * 2) //
        {
            ListNode *curr = headfind->next;
            ListNode *prev = headfind; //prev代表上两段排序后的结尾，用于承接上下两次排序
            while (curr != nullptr)
            {
                ListNode *head1 = prev->next;
                //先找第一段的结尾
                for (int i = 1; i < sub; i++)
                {
                    if (curr != nullptr)
                    {
                        curr = curr->next;
                    }
                    else
                    {
                        break;
                    }
                }
                //现在curr指向第一段的结尾
                ListNode *head2 = nullptr;
                if (curr != nullptr)
                {
                    head2 = curr->next;   //找到第二段的开头，可能是空
                    curr->next = nullptr; //将两段之间割裂开，使第一段成为一个独立的链表
                }
                curr = head2;
                for (int i = 1; i < sub; i++)
                {
                    if (curr != nullptr)
                    {
                        curr = curr->next;
                    }
                    else
                    {
                        break;
                    }
                }
                //现在curr指向第二段结尾
                ListNode *nexthead = nullptr;
                if (curr != nullptr)
                {
                    nexthead = curr->next; //第三段的开头
                    curr->next = nullptr;  //将第二段割裂开，使第二段成为一个单独的链表
                }
                prev->next = merge(head1, head2); //将合并好的链表与先前的合并好的链表拼接起来
                //得到当前链表的尾部
                while (prev->next != nullptr)
                {
                    prev = prev->next;
                }
                prev->next = nexthead; //与还未合并好的链表拼接起来
                curr = prev->next;     //curr指向下一段的头
            }
        }
        head = headfind->next;
        delete headfind;
        return head;
    }

private:
    ListNode *merge(ListNode *head1, ListNode *head2) //合并两个已排序的链表，并返回合并后的头节点
    {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
                curr = curr->next;
            }

            //将另一列不空的队列补上
        }
        curr->next = (head1 == nullptr ? head2 : head1);
        curr=head->next;//将curr指向排序好的链表开头，以便释放head
        delete head;
        return curr;
    }
};

// @lc code=end
