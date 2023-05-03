/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include <vector>
#include <string>
#include<limits.h>
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int word1Len = word1.size();
        int word2Len = word2.size();
        vector<vector<int>> dp(word1Len + 1, vector<int>(word2Len + 1, INT_MAX));
        // dp[i][j]代表word1(0~i-1)和word2(0~j-1)相等需要删除的最小字符串个数
        for (int i = 1; i < word1Len+1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j < word2Len+1; j++)
        {
            dp[0][j] = j;
        }
        dp[0][0] = 0;
        for (int i = 1; i < word1Len+1; i++)
        {
            for (int j = 1; j < word2Len+1; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    //字符不相等，需要删除其中的一个
                    //选择删除dp[i-1][j],dp[i][j-1]中较大的那一个
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1; 
                }
            }
        }
        return dp[word1Len][word2Len];
    }
};
// @lc code=end
