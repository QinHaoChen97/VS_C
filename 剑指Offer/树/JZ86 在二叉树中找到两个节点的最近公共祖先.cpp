//https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116?tpId=13&tqId=1024325&ru=/practice/965fef32cae14a17a8e86c76ffe3131f&qru=/ta/coding-interviews/question-ranking
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//https://blog.nowcoder.net/n/1195f0380d404496aeab25609fae2c7d
//这里是里面的解法2，也可以用解法1找到到o1和o2的路径，因为有公共祖先，所以路径的前一部分是相同的，最后一个相同的节点即为最近祖先，满足条件的前提是节点的val都不同
//如果val相同的话，路径需要用节点的指针来存储
class Solution
{
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int o1, int o2)
    {
        if (root==nullptr)
        {
            return -1;
        }
        return have_node(root,o1,o2)->val;
        
    }
    TreeNode* have_node(TreeNode* node,const int& o1,const int& o2)
    {
        if (node==nullptr)
        {
            return nullptr;
        }

        if (node->val==o1 || node->val==o2) 
        //当前节点为其中一个要找的节点，如果另一节点为当前节点的子孙，那么当前节点即为父节点，一直返回当前节点结束递归即可
        //另一种情况是另一个节点在父节点的另一个分支上
        //这两种情况都说明不必继续往下递归了，及时剪枝
        {
            return node;
        }
        
        TreeNode* leftnode=have_node(node->left,o1,o2);
        TreeNode* rightnode=have_node(node->right,o1,o2);

        if (leftnode!=nullptr && rightnode!=nullptr) //节点在当前节点的左右分支找到，说明当前节点即为最近祖先
        {
            return node;
        }
        else if (leftnode!=nullptr)
        {
            return leftnode;
        }
        else if (rightnode!=nullptr)
        {
            return rightnode;
        }
        else
        {
            return nullptr;
        }  
    }
};