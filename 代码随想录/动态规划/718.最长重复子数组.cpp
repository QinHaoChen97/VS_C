/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1Len = nums1.size();
        int nums2Len = nums2.size();
        if (nums1Len == 0 || nums2Len == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(nums1Len+1,vector<int>(nums2Len+1,0));
        //dp[i][j]代表nums1(0~i-1)与nums2(0~j-1)的最长公共数组的长度
        //显然dp[i][0],dp[0][j]=0
        int result=0;
        for (int i = 1; i < nums1Len+1; i++)
        {
            for (int j = 1; j < nums2Len+1; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    result=max(dp[i][j],result);
                }
                else
                {
                    //dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return result;
        
    }
};
// @lc code=end
