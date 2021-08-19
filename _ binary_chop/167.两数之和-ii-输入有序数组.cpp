// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem167.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
//直接双指针做了
//用二分查找的思路是target-numbers[i],查找这个差值在numbers中是否存在，但这样意义很小
//这样的思路用Hash表来实现更简单
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        while (numbers[left]+numbers[right]!=target)
        {
            if (numbers[left]+numbers[right]>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return vector<int>{left+1,right+1};
    }
};
// @lc code=end

