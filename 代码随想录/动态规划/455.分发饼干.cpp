/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
//这题用动态规划的写法会超时
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gLen=g.size();
        int sLen=s.size();
        if(gLen==0 || sLen==0)
        {
            return 0;
        }
        vector<vector<int>> dp(gLen+1,vector<int>(sLen+1,0));
        for (int i = 1; i <= gLen; i++)
        {
            for (int j = 1; j <= sLen; j++)
            {
                if(s[j-1]>=g[i-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
            
        }
        return dp[gLen][sLen];
        
    }
};
// @lc code=end

