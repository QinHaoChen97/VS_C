/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
template<typename T>
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                m[nums1[i] + nums2[j]]++;
            }
        }
        int count = 0;
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                if (m.find(0 - nums3[i] - nums4[j]) != m.end())
                {
                    count += m[0 - nums3[i] - nums4[j]];
                }
            }
        }
        return count;
    }
};
// @lc code=end
