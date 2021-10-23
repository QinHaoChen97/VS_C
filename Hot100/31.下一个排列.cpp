// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem31.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int nums_len = nums.size();
        int flag = -1;
        for (int i = nums_len - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                flag = i;
                break;
            }
        }
        if (flag == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int min_num = nums[flag - 1]; //要交换的较小的数字
        //找较大数的位置
        int max_num_pos;
        for (int i = nums_len - 1; i >= flag; i--)
        {
            if (nums[i]>min_num)    
            {
                max_num_pos=i;
                break;
            }
            
        }
        swap(nums[flag-1],nums[max_num_pos]);

        //对交换后的[flag,nums_len)位置进行反转，使之成为升序
        //reverse(nums.begin()+flag,nums.end());
        //可以直接用reserve，这里写一下双指针的做法
        int left=flag,right=nums_len-1;
        while (left<right)
        {
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
        
        return;
    }
};
// @lc code=end
