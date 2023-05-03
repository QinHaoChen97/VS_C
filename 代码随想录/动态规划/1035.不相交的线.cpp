/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int nums1Len=nums1.size();
        int nums2Len=nums2.size();
        if(nums1Len==0 || nums2Len==0)
        {
            return 0;
        }
        vector<vector<int>> dp(nums1Len+1,vector<int>(nums2Len+1,0));
        for (int i = 1; i < nums1Len+1; i++)
        {
            for (int j = 1; j < nums2Len+1; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[nums1Len][nums2Len];
        
    }
};
// @lc code=end

