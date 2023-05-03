// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int len = books.size();
        vector<int> dp(len+1,1000000);
        dp[0]=0;
        for (int i = 0; i < len; i++)
        {
            int width = 0;
            int maxhigh = 0;
            for (int j = i; j >=0 ; j--)
            {
                width+=books[j][0];
                if(width>shelfWidth)
                {
                    break;
                }
                maxhigh =  max(maxhigh,books[j][1]);
                dp[i+1]= min(dp[i+1],dp[j]+maxhigh);
            }
            
        }
        return dp[len];
        
    }
};
// @lc code=end

