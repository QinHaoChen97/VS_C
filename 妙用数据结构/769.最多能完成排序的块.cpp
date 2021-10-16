/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
//https://leetcode-cn.com/problems/max-chunks-to-make-sorted/solution/zui-duo-neng-wan-cheng-pai-xu-de-kuai-i-by-leetcod/
//和以往熟悉的动态规划不同，为主要是要找到规律
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int ans=0;
       int Max=0;
       for (int i = 0; i < arr.size(); i++)
       {
           Max=max(arr[i],Max);
           if (Max==i)
           {
               ans++;
           }
           
       }
       return ans;
    }
};
// @lc code=end

