/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(),false);
        int sum = 0;
        backtracking(candidates,0,sum,target,used);
        return ans;
    }
    void backtracking(vector<int> &candidates, int pos, int &sum,const int& target,vector<bool>& used)
    {
        if(sum==target)
        {   
            ans.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++)
        {
            if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==false) //这里是i-1不是i
            {
                continue;
            }
            if(sum+candidates[i]>target)
            {
                return;
            }
            else
            {
                path.push_back(candidates[i]);
                sum+=candidates[i];
                used[i]=true; // 这一个树的分支上用过了
                backtracking(candidates,i+1,sum,target,used);
                used[i]=false; // 这一层上用过这个树了
                sum-=candidates[i]; 
                path.pop_back();
            }
            
        }
        
    }
};
// @lc code=end
