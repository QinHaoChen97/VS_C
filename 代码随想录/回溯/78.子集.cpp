/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return ans;
    }
    void backtracking(const vector<int>& nums,int pos)
    {
        ans.push_back(path);
        if(pos>=nums.size())
        {
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        
    }
};
// @lc code=end

