// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem496.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1Len = nums1.size();
        int nums2Len = nums2.size();
        vector<int> ans(nums1Len, -1);
        unordered_map<int, int> m;
        for (int i = 0; i < nums1Len; i++)
        {
            m[nums1[i]] = i;
        }
        stack<int> sta;
        for (int i = 0; i < nums2Len; i++)
        {
            while (!sta.empty())
            {
                auto tmp = sta.top();
                if (nums2[i] > tmp)
                {
                    if(m.find(tmp)==m.end())
                    {
                        sta.pop();
                        continue;
                    }
                    ans[m[tmp]] = nums2[i];
                    sta.pop();
                }
                else
                {
                    break;
                }
            }
            sta.push(nums2[i]);
        }
        return ans;
    }
};
// @lc code=end
