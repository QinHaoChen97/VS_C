// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int s_size = s.size();
        vector<int> dp(s_size + 1, 0); //dp[i]代表s[0]-s[i-1](i>1)能不能拆分成单词，dp[0]=true
        dp[0]=1;
        for (int i = 1; i <= s_size; i++)
        {
            for (const auto &w : wordDict)
            {
                int n = w.length();
                if (i >= n && s.substr(i - n, n) == w)
                {
                    dp[i] = dp[i-n];
                    if (dp[i]==true)
                    {
                        break;
                    }
                    
                }
            }
        }
        return (bool)dp[s_size];
    }
};
// @lc code=end
