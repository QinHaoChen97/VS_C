//https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=23451&ru=/practice/8b3b95850edb4115918ecebdf1b4d222&qru=/ta/coding-interviews/question-ranking


struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr)
    {
    }
};
//https://blog.nowcoder.net/n/737a842c39d6473db2a10d4f1de7610c
//忘了的话可以看上面这种参照，但实际上写多了中序遍历已经可以不看了
class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    { //没什么技巧，根据中序遍历的逻辑来找便是了,注意这并不是一颗二叉搜索树，这是一颗普通树，不过根本上没什么区别
        if (pNode == nullptr)
        {
            return nullptr;
        }
        if (pNode->right != nullptr) //情况1，当前节点有右子节点
        {
            auto p = pNode->right;
            while (p->left != nullptr)
            {
                p = p->left;
            }
            return p;
        }
        
        if (pNode->next!=nullptr) //父节点不为空
        {
            //判断当前节点为左子节点还是右子节点
            if (pNode->next->left == pNode) //如果是左子节点，那么后继即为其父节点
            {
                return pNode->next;
            }
            else //为右节点
            {
                auto p = pNode->next;
                //不断往左上方找，并判断左上方的节点是否为左孩子节点
                while (p->next!=nullptr)
                {
                    if (p->next->left==p) //当前节点为左孩子节点
                    {
                        return p->next;
                    }
                    p=p->next;
                }
                
            }
        }
        //pNode的父节点为空（说明pNode是整棵树的根,且其没有右孩子）或者顺着左上方找到了根节点，说明当前节点没有后继
        return nullptr;
    }
};