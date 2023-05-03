/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int costLen=cost.size();
        if(costLen<=2) //可以从0或1的台阶开始爬，不需要费用
        {
            return min(cost[0],cost[1]);
        }
        vector<int> dp(costLen+1,0); //dp[i]为到达当前台阶需要支付的最小费用
        dp[0]=0;
        dp[1]=0;
        for (int i = 2; i < costLen+1; i++) //从下标为0的开始爬
        {
            dp[i]+=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
            cout<<i<<"="<<dp[i]<<endl;
        }
        return dp[costLen];
    }
};
// @lc code=end

