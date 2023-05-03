/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //输入两遍，第二遍只输入到nums.size()-1即可
        int numsLen=nums.size();
        stack<int> sta;
        vector<int> ans(numsLen,-1);
        for (int i = 0; i < numsLen; i++)
        {
            while (!sta.empty())
            {
                auto pos=sta.top();
                if(nums[i]>nums[pos])
                {
                    sta.pop();
                    ans[pos]=nums[i];
                }
                else
                {
                    break;
                }
                
            }
            sta.push(i);
        }
        //第二遍不需要push
         for (int i = 0; i < numsLen-1; i++)
        {
            while (!sta.empty())
            {
                auto pos=sta.top();
                if(nums[i]>nums[pos])
                {
                    sta.pop();
                    ans[pos]=nums[i];
                }
                else
                {
                    break;
                }
                
            }
            if(sta.empty())
            {
                return ans;
            }
        }
        return ans;
        
    }
};
// @lc code=end

