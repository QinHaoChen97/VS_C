/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int count;
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1,0);
        // dp[0]=1;
        // sort(nums.begin(),nums.end());
        // for (int j = 1; j < target+1; j++) //{1,2}和{2,1}不同，所以要先遍历背包，再遍历物品
        // {
        //     for(const auto& num:nums)
        //     {
        //         if(num>j || dp[j - num] > INT_MAX - dp[j]) //已经做了升序排序
        //         {
        //             break;
        //         }
        //         dp[j]+=dp[j-num];
        //     }
            
        //     cout<<dp[j]<<endl;
        // }
        // return dp[target];
        count=0;
        dfs(nums,0,target);
        return count;
    }
    void dfs(const vector<int>& nums,int sum,const int& target)
    {
        if(sum>target)
        {
            return;
        }
        if(sum==target)
        {
            count++;
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            dfs(nums,sum,target);
            sum-=nums[i];
        }
        
    }
    
};
// @lc code=end

