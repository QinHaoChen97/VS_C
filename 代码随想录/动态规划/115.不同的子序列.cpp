/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int sLen = s.size(), tLen = t.size();
        if(tLen>sLen)
        {
            return 0;
        }
        vector<vector<uint64_t>> dp(sLen + 1, vector<uint64_t>(tLen + 1, 0));
        for (int i = 1; i < sLen; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j < tLen; j++)
        {
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
        for (int i = 1; i < sLen + 1; i++)
        {
            for (int j = 1; j < tLen + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[sLen][tLen];
    }
};
// @lc code=end
