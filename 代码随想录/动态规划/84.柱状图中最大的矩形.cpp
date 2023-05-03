// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem84.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        unsigned int heightsLen = heights.size();
        if (heightsLen == 1)
        {
            return heights[0];
        }
        stack<int> sta;
        int ans = 0;
        for (int i = 0; i < heightsLen; i++)
        {
            while (!sta.empty() && heights[sta.top()] > heights[i])
            {
                int weight;
                int high=heights[sta.top()];
                sta.pop();
                if (sta.empty())
                {
                    weight = i;
                }
                else
                {
                    weight = i - sta.top()-1;
                }
                ans = max(ans, weight * high);
            }
            sta.push(i);
        }
        while (!sta.empty())
        {
            int i = sta.top();
            int weight;
            sta.pop();
            if (sta.empty())
            {
                weight = heightsLen;
            }
            else
            {
                weight = heightsLen-sta.top()-1;
            }
            ans = max(ans, weight * heights[i]);
        }
        return ans;
    }
};
// @lc code=end
