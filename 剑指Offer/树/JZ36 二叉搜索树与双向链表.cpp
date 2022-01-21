//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=23253&ru=/practice/8b3b95850edb4115918ecebdf1b4d222&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};
#include<queue>
using std::queue;
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree==nullptr)
        {
            return pRootOfTree;
        }
        
        queue<TreeNode*> q;
        mid_dfs(q,pRootOfTree);

        TreeNode* head=q.front();
        q.pop();
        head->left=nullptr;
        TreeNode* current_node=head;
        while (!q.empty())
        {
            current_node->right=q.front();
            q.front()->left=current_node;
            current_node=q.front();
            q.pop();
        }
        current_node->right=nullptr; //尾节点的尾指针指向nullptr
        return head;
        
    }
    void mid_dfs(queue<TreeNode*>& q,TreeNode* node)
    {
        if (node==nullptr)
        {
            return;
        }
        mid_dfs(q,node->left);
        q.emplace(node);
        mid_dfs(q,node->right);
        return;
    }
};
//利用的原理是，二叉树中，当前节点如果有右节点，那么它的直接后继为其右节点的最左子孙节点
//如果没有右节点，则其直接后继为其左子节点
class Solution1 {
public:
    TreeNode* pro_node;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree==nullptr)
        {
            return nullptr;
        }
        //找到头节点
        auto p=pRootOfTree;
        while (p->left!=nullptr)
        {
            p=p->left;
        }
        pro_node=nullptr;
        inorder(pRootOfTree);
        return p;
        
        
    }
    void inorder(TreeNode* node)
    {
        if (node==nullptr)
        {
            return;
        }
        inorder(node->left);  
        //遍历完左节点后返回，前继节点为当前节点
        node->left=pro_node;
        if (pro_node!=nullptr)
        {
            pro_node->right=node;
        }
        pro_node=node;
        inorder(node->right);
        return;
    }
};