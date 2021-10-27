// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem56.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int intervals_length = intervals.size();
        if (intervals_length <= 1)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals_length; i++)
        {
            if (right>=intervals[i][0])
            {
                right=max(right,intervals[i][1]);
            }
            else
            {
                //是分割的区间
                ans.push_back(vector<int>{left,right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
            
        }
        ans.push_back(vector<int>{left,right});
        return ans;
    }
};
// @lc code=end
