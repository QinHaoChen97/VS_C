// https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=23294&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};
#include<algorithm>
class Solution { //节点最终的深度等于左右子树中较深的深度+1
public:
    int TreeDepth(TreeNode* pRoot) {
        return dfs(pRoot);
    }
private:
    int dfs(TreeNode* node)
    {
        if (node==nullptr)
        {
            return 0;
        }
        return std::max(dfs(node->left),dfs(node->right))+1;
        
    }
};