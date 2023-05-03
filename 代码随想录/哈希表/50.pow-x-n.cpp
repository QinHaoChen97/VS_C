// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem50.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (x == 0 || x == 1 || n == 1)
        {
            return x;
        }

        //防止INT_MIN取反溢出
        long long int tmp_n = n;
        if (n < 0)
        {
            x = 1 / x;
            tmp_n = -tmp_n;
        }
        return dfs(x, tmp_n);
    }
    double dfs(const double &x, long long int n)
    {
        if (n == 1)
        {
            return x;
        }
        if (n % 2 == 1)
        {
            n = n - 1;
            double tmp = dfs(x, n / 2);
            return tmp * tmp * x;
        }
        else
        {
            double tmp = dfs(x, n / 2);
            return tmp * tmp;
        }
    }
};
// @lc code=end
