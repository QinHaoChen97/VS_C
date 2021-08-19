/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
//https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
//参考的题解，但应该指出数字都包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n）
//且nums 只有 一个重复的整数 
//这样才能满足抽屉原理的要求

//这里的二分查找将要找的值和数组的位置做了关联
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int mid,cnt;
        while (left<right)
        {
            mid=left+(right-left)/2;
            cnt=0;
            for (auto num:nums)
            {
                if (num<=mid)
                {
                    cnt++;
                }
            }
            if (cnt>mid)  //抽屉原理
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }            
            
        }
        return left;//return right
        
    }
};
// @lc code=end

