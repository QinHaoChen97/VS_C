// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem719.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        int left=0,right=nums[nums_size-1]-nums[0];//right等于最大距离
        int mid;
        while (left<right)
        {
            mid=left+(right-left)/2;
            if(check(nums,k,mid))//大于k,应该往[left,mid]中找
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
            
        }
        return left;
        
    }

private:
//滑动双指针的方法
//https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/solution/pai-xu-er-fen-hua-chuang-zhi-yao-8ms-by-fqpaz/
    bool check(vector<int> &nums,int k,int mid)//用于判断距离小于Mid的个数是否超过k
    {
        int l=0,r=0,count=0;
        for (r ; r < nums.size(); r++)
        {
            while (l<r && nums[r]-nums[l]>mid)
            {
                l++;
            }
            count+=(r-l);
        }
        return count>=k;
    }
};
// @lc code=end

