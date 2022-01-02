//https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=23454&ru=/practice/445c44d982d04483b04a54f298796288&qru=/ta/coding-interviews/question-ranking
#include <vector>
#include <queue>
#include<algorithm>
using std::queue;
using std::vector;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot==nullptr)
        {
            return {};
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<vector<int>> ans;
        int i=0; //记录层数
        while (!q.empty()) //层序遍历
        {
            int count=q.size();
            ans.push_back({});
            while (count>0)
            {
                count--;
                auto node=q.front();
                q.pop();
                ans[i].push_back(node->val);
                if (node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if (node->right!=nullptr)
                {
                    q.push(node->right);
                }
                
                
                
            }
            i++;//下一层
        }
        //此时i的为实际层数，但ans中对应的是i-1
        for (int reserve = 1; reserve<i ; reserve+=2) //翻转需要翻转的层数
        {
            std::reverse(ans[reserve].begin(),ans[reserve].end());
        }
        return ans;
        
        
    }
    
};