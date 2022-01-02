//https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=23254&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include<unordered_map>
using std::unordered_map;
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr)
    {
    }
};
//https://blog.nowcoder.net/n/4c8621e3c72f4956b81813427abe3140?f=comment
//解法2中的算法拆分可以不用哈希表构建映射关系，缩减了空间复杂度，二刷的时候可以做。
class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        //使用Map保持映射关系
        unordered_map<RandomListNode*,RandomListNode*> m;
        auto current_node=pHead;
        //生成新链表的节点
        while (current_node!=nullptr) //假设没有环，有环的话加一个m.find(current_node)的判断
        {
            m[current_node]=new RandomListNode(current_node->label);
            current_node=current_node->next;
        }
        current_node=pHead;
        //将旧链表的映射关系与新链表对应
        while (current_node!=nullptr)
        {
            m[current_node]->next=m[current_node->next];
            m[current_node]->random=m[current_node->random];
            current_node=current_node->next;
        }
        return m[pHead];
    }
};