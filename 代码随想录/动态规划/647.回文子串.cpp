/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int sLen=s.size();
        if(sLen==0)
        {
            return 0;
        }
        if(sLen==1)
        {
            return 1;    
        }
        vector<vector<bool>> dp(sLen,vector<bool>(sLen,false));
        int count=0;
        for (int i = 0; i < sLen; i++)
        {
            dp[i][i]=true;
            count++;
        }
        for (int i = sLen-1; i >=0 ; i--)
        {
            for (int j = i+1; j < sLen; j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i<=1)
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                    if(dp[i][j])
                    {
                        count++;
                    }
                }
                
            }    
        }
        return count;
        
    }
};
// @lc code=end

