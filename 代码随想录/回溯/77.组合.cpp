/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        if(n<k || k==0)
        {
            return {};
        }
        dfs(1,k,n);
        return ans;
    }
    void dfs(int pos,const int& k,const int& n)
    {
        if(path.size()==k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = pos; i <= n; i++)
        {
            path.push_back(i);
            dfs(i+1,k,n);
            path.pop_back();
        }
        
    }
};
// @lc code=end

