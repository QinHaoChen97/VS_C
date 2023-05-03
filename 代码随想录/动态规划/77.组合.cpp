/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.emplace_back(i);
        }
        cout<<nums.size()<<endl;
        ans.clear();
        vector<int> path;
        dfs(path,0,nums,k);
        return ans;
    }
    vector<vector<int>> ans;
    void dfs(vector<int>& path,int start,const vector<int>& nums,const int& k)
    {
        if(path.size()==k)
        {
            ans.emplace_back(path);
            return;
        }
        if(start>=nums.size())
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            path.emplace_back(nums[i]);
            dfs(path,i+1,nums,k);
            path.pop_back();
        }
        
    }
};
// @lc code=end

