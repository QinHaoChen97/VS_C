/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesLen=prices.size();
        vector<int> dp(pricesLen,0); //dp[i]代表当天能获取的最大利润
        //这里没有用经典的股票dp数据来写
        //更类似于贪心的思想
        //计算出prices[i]-prices[i-1]的差
        //相加直到和小于0再将初值置为0，重新开始计算    
        for (int i = 1; i < pricesLen; i++)
        {
            if(dp[i-1]>=0)
            {
                dp[i]=max(dp[i-1]+(prices[i]-prices[i-1]),0);
                cout<<dp[i]<<endl;
            }
            else
            {
                dp[i]=0; //可以不写，因为初始化就是0
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};
// @lc code=end

