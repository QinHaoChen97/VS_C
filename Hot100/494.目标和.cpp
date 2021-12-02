/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include<vector>
using std::vector;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for (auto &num : nums)
        {
            sum+=num;
        }
        if (target>sum || target<-sum)//sum(nums[i])>0
        {
            return 0;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,0));
        dp[0][sum]=1;
        for (int row = 0; row < nums.size(); row++)
        {
            for (int col = 0; col < 2*sum+1; col++)
            {
                if (dp[row][col]!=0)
                {
                    dp[row+1][col-nums[row]]+=dp[row][col];
                    dp[row+1][col+nums[row]]+=dp[row][col];
                }
                
            }
            
        }
        return dp[dp.size()-1][sum+target];//https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-by-cheungq-6-h1dz/
        //通过这个图去理解。
        
    }
};
// @lc code=end

