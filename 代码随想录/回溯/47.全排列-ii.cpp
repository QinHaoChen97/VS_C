/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int numsLen=nums.size();
        vector<bool> used(numsLen,false);
        sort(nums.begin(),nums.end());
        backtracking(nums,used);
        return ans;
    }
    void backtracking(const vector<int>& nums,vector<bool>& used)
    {
        if(path.size()==nums.size())
        {
            ans.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false)
            {
                continue;
            }
            if(used[i]==true)
            {
                continue;
            }
            else
            {
                path.emplace_back(nums[i]);
                used[i]=true;
                backtracking(nums,used);
                used[i]=false;
                path.pop_back();
            }
            
        }
        
    }
};
// @lc code=end

