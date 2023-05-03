/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum=0;
        backtracking(candidates,target,sum,0);
        return ans;
    }
    void backtracking(vector<int>& candidates,const int& target,int& sum,int pos)
    {
        if(sum==target)
        {
            ans.push_back(path);
        }
        for (int i = pos; i < candidates.size(); i++)
        {
            if(sum+candidates[i]<=target)
            {
                sum+=candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates,target,sum,i);
                path.pop_back();
                sum-=candidates[i];
            }
            else
            {
                return;
            }
            
        }
        
    }
};
// @lc code=end

