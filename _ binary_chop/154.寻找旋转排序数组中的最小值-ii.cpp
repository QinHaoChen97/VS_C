// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem154.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==1)
        {
            return nums[0];
        }
        
        int left=0,right=nums_size-1;
        int mid;
        while (left+1<right)
        {
            mid=left+(right-left)/2;
            if (nums[mid]>nums[nums_size-1])
            {
                left=mid;
            }
            else if(nums[mid]<nums[nums_size-1])
            {
                right=mid;
            }
            else//用来对相等的数刚好是最后一位做区分
            {
                int flag=mid+1;
                while (flag<nums_size-1)
                {
                    if(nums[flag]==nums[nums_size-1])
                    {
                        flag++;
                    }
                    else
                    {
                        left=mid;
                        break;
                    }
                }
                if (flag==nums_size-1)
                {
                    right=mid;
                }
                
                
            }
            
            
            
        }
        //end_condiction
        return nums[left]>nums[left+1]?nums[left+1]:nums[left];
        
    }
};
// @lc code=end
//官方解法，直接去掉最右的端点继续进行比较
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;//点睛之笔
            }
        }
        return nums[low];
    }
};

