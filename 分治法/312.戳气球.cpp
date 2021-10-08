/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://leetcode-cn.com/problems/burst-balloons/solution/chuo-qi-qiu-by-leetcode-solution/
//参考这个
//其实看完了分治法再往下看动态规划就会很清晰
//这道题来说动态规划理解起来更为容易
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int len = nums.size();
        nums.push_back(1);
        nums.emplace(nums.begin(), 1);
        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
        //从外层开始循环
        /**
 * dp版本代码，最外层的循环，i为什么是n-1 -> 0，而不能反过来？
 * (i,j) 0 1  2   3   4   ...   n-2   n-1   n   n+1
 * 0     0 1  2   3   4   ...                   n+1
 * 1       1  2   3   4   ...                   n+1
 * 2          2   3   4   ...                   n+1
 * 3              3   4   ...                   n+1
 * 4                  4                         n+1
 * .                      .                     .
 * .                         .                  .
 * n-2                          n-2   n-1   n   n+1
 * n-1                                n-1   n   n+1
 * n+1
 *
 * 须从下往上算，即先算dp[n-1][n+1]：
 * 根据递推关系，算dp[i][j]时依赖的dp[i][k]和dp[k][j]，其中i<k<j。
 * 1、如果从上往下计算，依赖的dp[k][j]根本就还未算出（k比i大），比如算dp[0][3]时，依赖的dp[1][3]还是个未知数。
 * 2、从下往上就不一样，算dp[i][j]时，依赖的dp[i][k]，位于同一行左侧，已计算过；
 *                                    依赖的dp[k][j]，因为k>i，位于更下面的行，也已计算过。
 */
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < len + 2; j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    int sum=nums[i]*nums[k]*nums[j];
                    sum+=dp[i][k]+dp[k][j];
                    //sum可以认为num[k]是区间（i,j）中最后删除的是num[k]可以得到的值
                    //所以有nums[i]*nums[k]*nums[j]
                    dp[i][j]=max(dp[i][j],sum);

                }
            }
        }

        return dp[0][len+1];
    }
};
// @lc code=end
