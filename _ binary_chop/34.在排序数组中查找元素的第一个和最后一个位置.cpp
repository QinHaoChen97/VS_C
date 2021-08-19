// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int nums_size=nums.size();
        if (nums_size==0)
        {
            return {-1,-1};
        }
        int left=0,right=nums_size-1;
        int mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if (nums[mid]==target)
            {
                break;
            }
            else if (nums[mid]>target)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        //终止条件为left==right或者找到其中一个目标
        if (left==right)
        {
            if (nums[right]==target)
            {
                return {left,right};
            }
            else
            {
                return {-1,-1};
            }
            
        }
        else
        {
            left=mid;
            right=mid;
            while (left>0 && nums[left-1]==target)//这样写的话就满足不了时间复杂度的要求了
            {
                left--;
            }
            while (right<nums_size-1 && nums[right+1]==target)
            {
                right++;
            }
            return {left,right};
            
        } 
    }
};
// @lc code=end

//下面这种写法使用两次二分查找，可以满足log(n)复杂度的要求
// 主函数
vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
        return vector<int>{-1, -1};
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1; // 这里需要减1位
    if (lower == nums.size() || nums[lower] != target)
    {
        return vector<int>{-1, -1};
    }
    return vector<int>{lower, upper};
}
// 辅函数
int lower_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size(), mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (nums[mid] >= target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
// 辅函数
int upper_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size(), mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (nums[mid] > target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}