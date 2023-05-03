// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem474.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //都初始化为0
        for (int k = 0; k < strs.size(); k++)
        {
            auto tmp = zero_one(strs[k]);
            int zero = tmp[0];
            int one = tmp[1];
            for (int i = m; i >= 0; i--)
            {

                for (int j = n; j >= 0; j--)
                {

                    if (zero <= i && one <= j)
                    {
                        dp[i][j] = max(dp[i - zero][j - one] + 1, dp[i][j]);
                    }
                }
            }
        }
        return dp[m][n];
    }
    vector<int> zero_one(const string &str)
    {
        int zero = 0;
        int one = 0;
        for (const auto &s : str)
        {
            if (s == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        return vector<int>{zero, one};
    }
};
// @lc code=end
