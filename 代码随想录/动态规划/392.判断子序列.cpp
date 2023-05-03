// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem392.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int sLen = s.size(), tLen = t.size();
        if (sLen == 0)
        {
            return true;
        }
        if (tLen == 0)
        {
            return false; // t=""，s!=""
        }
        vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1, 0));
        // dp[i][j]为当前s(0~j-1)匹配t(0~i-1)中的字母的个数
        for (int i = 1; i < sLen + 1; i++)
        {
            for (int j = 1; j < tLen + 1; j++)
            {
                if (s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] == sLen)
                    {
                        return true;
                    }
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return false;
    }
};
// @lc code=end
