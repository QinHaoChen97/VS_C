// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem91.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1); //dp[0]为一个初始值
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            if (s[i - 1] != '0') //dp[i]对应s[i-1]
            {
                dp[i] += dp[i - 1]; //如果不等于0，dp[i]至少有dp[i-1]种组合，即在原组合的基础上加上自身
            }
            if (i>1 && s[i-2]!='0' &&  (s[i-2]-'0')*10+s[i-1]-'0'<=26)
            {
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
