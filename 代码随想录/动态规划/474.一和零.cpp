/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int strsLen = strs.size();
        vector<vector<vector<int>>> dp(strsLen, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        vector<int> zero_one = ZeroOne(strs[0]);
        int zero = zero_one[0];
        int one = zero_one[1];
        for (int i = zero; i < m + 1; i++)
        {
            for (int j = one; j < n + 1; j++)
            {
                dp[0][i][j] = 1;
            }
        }
        for (int i = 1; i < strsLen; i++)
        {
            vector<int> tmp=ZeroOne(strs[i]);
            int cur_zero=tmp[0];
            int cur_one=tmp[1];
           // int value=1;  //当前背包问题的value即为答案里字符串的个数，所以value=1
            for (int j = 0; j < m + 1; j++)
            {
                for (int k = 0; k < n + 1; k++)
                {
                    if(cur_zero<=j && cur_one<=k)
                    {
                        dp[i][j][k]=max(dp[i-1][j-cur_zero][k-cur_one]+1,dp[i-1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                    
                }
            }
        }
        return dp[strsLen-1][m][n];
    }
    vector<int> ZeroOne(const string &str)
    {
        int zero = 0;
        int one = 0;
        for (auto &s : str)
        {
            if (s == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        return {zero, one};
    }
};
// @lc code=end
