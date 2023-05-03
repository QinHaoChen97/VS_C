/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(const auto &stone:stones)
        {
            sum+=stone;
        }
        int target=sum/2;
        vector<int> dp(target+1,0);
        //dp[0]=0;
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >=stones[i]; j--)
            {
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
            
        }
        // int sub=0;
        // for(int j=target; j>=0; j--)
        // {
        //     if(dp[j]!=0)
        //     {
        //         sub=j;
        //         break;
        //     }
        // }
        return abs((sum-dp[target])-dp[target]);
        
    }
};
// @lc code=end

