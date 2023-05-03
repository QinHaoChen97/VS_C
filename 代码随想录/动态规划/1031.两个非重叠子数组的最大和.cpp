/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
#include<vector>
#include<math.h>
#include <numeric>
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        return max(help(nums, firstLen, secondLen),help(nums, secondLen, firstLen));
    }
    int help(vector<int>& nums,int firstlen, int secondlen)
    {
        int sum_firstarr = accumulate(nums.begin(),nums.begin()+firstlen, 0);
        int max_sum_firstarr = sum_firstarr;
        int sum_secondarr = accumulate(nums.begin()+firstlen,nums.begin()+firstlen+secondlen,0);
        int ans = max_sum_firstarr + sum_secondarr;
        for (int i = firstlen+secondlen; i < nums.size(); i++)
        {
            sum_secondarr = sum_secondarr + nums[i] - nums[i-secondlen];
            sum_firstarr = sum_firstarr + nums[i-secondlen] - nums[i-secondlen-firstlen];
            max_sum_firstarr = max(max_sum_firstarr,sum_firstarr);
            ans = max(ans, max_sum_firstarr + sum_secondarr); 
        }
        return ans;
        
    }
};
// @lc code=end

