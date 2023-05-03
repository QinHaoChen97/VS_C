/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int sLen = s.size();
        if (sLen <= 1)
        {
            return 1;
        }
        vector<vector<int>> dp(sLen, vector<int>(sLen, 0));
        // dp[i][j]代表s(i-j)的最长回文子序列长度
        for (int i = sLen - 1; i >= 0; i--)
        {
            for (int j = 0; j < sLen; j++)
            {
                if (j >= i)
                {
                    if (s[i] == s[j])
                    {
                        if (j - i == 1)
                        {
                            dp[i][j] = 2;
                        }
                        else if (j - i == 0)
                        {
                            dp[i][j] = 1;
                        }
                        else
                        {
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j - 1],dp[i+1][j]);
                    }
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[0][sLen-1];
    }
};
// @lc code=end
