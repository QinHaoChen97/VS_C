/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int numsLen=nums.size();
        vector<bool> used(numsLen,false);
        backtracking(nums,used);
        return ans;
    }
    void backtracking(const vector<int>& nums,vector<bool>& used)
    {
        if(path.size()==nums.size())
        {
            ans.emplace_back(path);
        }
        for (int i = 0; i < nums.size(); i++)
        {
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

