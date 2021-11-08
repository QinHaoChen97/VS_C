/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // https://leetcode-cn.com/problems/product-of-array-except-self/solution/chu-zi-shen-yi-wai-shu-zu-de-cheng-ji-by-leetcode-/
        //题解参考
        vector<int> ans(nums.size());
        //为了实现O（1）复杂度，用ans来存放L[i]
        ans[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i - 1] * nums[i-1];
        }
        // ans[i]=L[i]*R[i]
        int R = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] = R * ans[i];
            R = R * nums[i];
        }
        return ans;
    }
};
// @lc code=end
