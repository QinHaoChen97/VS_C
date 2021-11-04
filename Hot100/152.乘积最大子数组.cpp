// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem152.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
//本质上这道题时动态规划，参考https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/
//写起来就很有章法
//现在这样的写法更类似于分类讨论，隐含着动态规划，但是写法看起来就很乱
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int mul_max = nums[0];
        int seg_min = nums[0]; //分段最小值(遇到0进行分段)
        int seg_max = nums[0]; //分段最大值
                               /* 可以这样从迭代器的第一个开始遍历，但是不美观
                               for (auto i = nums.begin()+1; i != nums.end(); i++)
                               {
                       
                               }
                               */
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                if (seg_min == 0 && seg_max == 0)
                {
                    seg_max = nums[i];
                    seg_min = nums[i];
                    //这里不需要比较，因为此时seg_max为负数，而mul_max此时一定大于等于0
                    //mul_max=max(mul_max,seg_max);
                    continue;
                }
                int middle=seg_min;
                if (seg_max>0 && seg_min<0) //seg_min和seg_max异号
                {
                    seg_min=seg_max*nums[i];
                    seg_max=middle*nums[i];
                }
                else if(seg_min<0 && seg_max<0)
                {
                    seg_max=seg_min*nums[i];
                    seg_min=nums[i];
                }
                else //seg_min>0 && seg_max>0
                {
                    seg_min=seg_max*nums[i];
                    seg_max=nums[i];
                }
                mul_max=max(mul_max,seg_max);
            }
            else if (nums[i] > 0)
            {
                if (seg_min == 0 && seg_max == 0)
                {
                    seg_max = nums[i];
                    seg_min = nums[i];
                    mul_max=max(mul_max,seg_max);
                    continue;
                }
                seg_min = seg_min * nums[i];
                if (seg_max < 0)
                {
                    seg_max = nums[i];
                }
                else
                {
                    seg_max = seg_max * nums[i];
                }
                mul_max=max(mul_max,seg_max);
            }
            else // nums[i]==0
            {
                seg_min = 0;
                seg_max = 0;
                mul_max = max(0, mul_max);
            }
        }
        return mul_max;
    }
};
// @lc code=end
