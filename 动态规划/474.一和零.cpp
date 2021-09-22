/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//https://leetcode-cn.com/problems/ones-and-zeroes/solution/dong-tai-gui-hua-zhuan-huan-wei-0-1-bei-bao-wen-ti/
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        //尝试使用三维的解法，二维的可以参考416题
        int strs_size = strs.size();
        //dp[i][j][k] 表示输入字符串在子区间 [0, i] 能够使用 j 个 0 和 k 个 1 的字符串的最大数量。
        vector<vector<vector<int>>> dp(strs_size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= strs_size; i++)
        {
            vector<int> count = zero_one(strs[i - 1]);
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    //先将上面一行抄下来，防止j<zero和k<zero的情况出现
                    dp[i][j][k]=dp[i-1][j][k];
                    int zero=count[0];
                    int one=count[1];
                    if (j>=zero && k>=one)
                    {
                        dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-zero][k-one]+1);
                    }
                    
                }
            }
        }
        return dp[strs_size][m][n];
    }
    vector<int> zero_one(const string &str)
    {
        vector<int> count(2, 0);
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '0')
            {
                count[0]++;
            }
            else
            {
                count[1]++;
            }
        }
        return count;
    }
};
// @lc code=end
