/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1Len=text1.size(),t2Len=text2.size();
        if(t1Len==0 || t2Len==0)
        {
            return 0;
        }
        vector<vector<int>> dp(t1Len+1,vector<int>(t2Len+1,0));
        //dp[i][j]代表text1(0,i-1)和text2(0,j-1)的最长公共子序列
        for (int i = 1; i < t1Len; i++)
        {
            for (int j = 1; j < t2Len; j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
        }
        return dp[t1Len][t2Len];
        
    }
};
// @lc code=end

