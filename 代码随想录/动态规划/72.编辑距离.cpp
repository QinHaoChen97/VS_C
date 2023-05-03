/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int word1Len = word1.size();
        int word2Len = word2.size();
        if (word1Len == 0)
        {
            return word2Len;
        }
        if (word2Len == 0)
        {
            return word1Len;
        }
        vector<vector<int>> dp(word1Len+1, vector<int>(word2Len+1, 0));
        for (int i = 0; i < word1Len+1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < word2Len+1; j++)
        {
            dp[0][j] = j;
        }
        dp[0][0] = 0;
        for (int i = 1; i < word1Len+1; i++)
        {
            for (int j = 1; j < word2Len+1; j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    //多了一次增加或者删除操作
                }
            }
        }
        return dp[word1Len][word2Len];
    }
};
// @lc code=end
