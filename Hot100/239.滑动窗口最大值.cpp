/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//模仿单调栈来实现
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int nums_len = nums.size();
        vector<int> ans;
        if (k >= nums.size())
        {
            int max_num = INT_MIN;
            for (const auto &num : nums)
            {
                max_num = max(max_num, num);
            }
            ans.push_back(max_num);
            return ans;
        }
        else
        {
            int left = 0, right = 1;
            deque<int> q;   //存放的是值的坐标而非值本身
            q.push_back(0); //第一个数先放入
            while (right < nums_len)
            {
                if (right - left == k) //滑动窗口已生成，这时候栈肯定不为空
                {
                    int pos = q.front();
                    ans.push_back(nums[pos]);
                    if (left + 1 > pos)
                    {
                        q.pop_front();
                    }
                    if (q.empty())
                    {
                        q.push_back(right);
                    }
                    else
                    {
                        while (!q.empty() && nums[right] > nums[q.back()])
                        {
                            q.pop_back();
                        }
                        q.push_back(right);
                    }
                    left++;
                    right++;
                } 
                else //滑动窗口未生成
                {
                    while (!q.empty() && nums[right] > nums[q.back()])
                    {
                        q.pop_back();
                    }
                    q.push_back(right);

                    right++;
                }
            }
            ans.push_back(nums[q.front()]); //最后一组的最大值没有压入，在这补充
            return ans;
        }
    }
};
// @lc code=end
