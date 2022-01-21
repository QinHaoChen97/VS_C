// https://www.nowcoder.com/practice/965fef32cae14a17a8e86c76ffe3131f?tpId=13&tqId=2277604&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//回溯+前缀树
//https://blog.nowcoder.net/n/9f3db96916704e1cae1b7ff4956d1bd2  这里还提出了一种两次dfs的方法，即不断以每个节点都作为根节点
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <map>
using std::map;
class Solution
{
public:
    map<int, int> trie; //前缀树
    int target;
    int FindPath(TreeNode *root, int sum)
    {
        int count=0;
        trie[0]=1;
        target=sum;
        dfs(root,count,0);
        return count;
    }
    void dfs(TreeNode *node, int &count,int sub_sum)
    {
        if (node==nullptr)
        {
            return;
        }
        sub_sum+=node->val; //当前的前缀和
        int diff=sub_sum-target; 
        if (trie.find(diff)!=trie.end()) 
        { 
            count+=trie[diff];
        }
        trie[sub_sum]+=1; //构建前缀树
        dfs(node->left,count,sub_sum);
        dfs(node->right,count,sub_sum);
        trie[sub_sum]-=1; //回溯
        return;
        
    }
};