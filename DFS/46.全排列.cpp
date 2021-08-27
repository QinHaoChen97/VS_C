/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
//回溯法，参考下面这个链接
//https://leetcode-cn.com/problems/permutations/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-mfrp/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int nums_len=nums.size();
        if (nums_len<=1)
        {
            return {nums};
        }
        vector<bool> used(nums_len,false);  //判断是否使用过这个数，vector<boo>不要随便用
        vector<vector<int>> ans;
        vector<int> path;
        backtracking(used,path,ans,nums);
        return ans;
    }
    void backtracking(vector<bool> &used,vector<int> path,vector<vector<int>> &ans,vector<int> &nums)
    {
        if (path.size()==nums.size())//找到一种排列方式
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)//其实算是一种暴力的解法
        {
            if (used[i]==true)
            {
                continue;
            }
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(used,path,ans,nums);
            //找到一种排列方式后回溯
            path.pop_back();
            used[i]=false;
        }
        
        
    }
};
// @lc code=end

