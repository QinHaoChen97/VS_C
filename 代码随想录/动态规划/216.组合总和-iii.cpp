/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for (int i = 1; i <= 9; i++)
        {
            nums[i-1]=i;
        }
        vector<int> path;
        dfs(path,nums,k,n,0);
        return ans;
    }
    void dfs(vector<int>& path,const vector<int>& nums,const int& k,const int& n,int start)
    {
        if(path.size()==k)
        {
            int sum=0;
            for (const auto n:path)
            {
                sum+=n;
            }
            if(sum==n)
                ans.emplace_back(path);
        }
        if(start>=9)
        {
            return;
        }
        for (int i = start; i<9 &&(k-path.size() <= 9-i); i++)
        {
            path.emplace_back(nums[i]);
            dfs(path,nums,k,n,i+1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> ans;
};
// @lc code=end

