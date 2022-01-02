//https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=23454&ru=%2Fpractice%2F435fb86331474282a3499955f0a41e8b&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
//JZ78题的简单版本
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
        while (!q.empty())
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
        return ans;
        
        
    }
    
};