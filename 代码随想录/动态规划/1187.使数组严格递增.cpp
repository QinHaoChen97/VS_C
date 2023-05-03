/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        auto it = unique(arr2.begin(), arr2.end());
        arr2.erase(it,arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n+1, vector<int>(min(m,n)+1,INT_MAX));
        dp[0][0] = -1;
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 0; j < min(i,m)+1; j++)
            {
                if(arr1[i-1] > dp[i-1][j])
                {
                    dp[i][j] = arr1[i-1];
                }
                if(j>0 && dp[i-1][j-1]!=INT_MAX)
                {
                    auto it = upper_bound(arr2.begin()+j-1, arr2.end(), dp[i-1][j-1]);
                    if(it != arr2.end())
                    {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
                if(i==n && dp[i][j]!=INT_MAX)
                {
                    return j;
                }
            }
            
        }
        return -1;
        

    }
};
// @lc code=end

