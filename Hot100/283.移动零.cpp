// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem283.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
/* 操作次数太多
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_len=nums.size();
        int zero_start=nums_len-1;
        int i=0;
        while (i<=zero_start) //开始存放0的位置
        {
            if (nums[i]==0)
            {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                zero_start--;

            }
            if (nums[i]!=0)
            {
                i++;
            }

        }

    }
};
*/
//快慢指针的解法
// https://leetcode-cn.com/problems/move-zeroes/solution/283-yi-dong-ling-shuang-zhi-zhen-xiang-jie-by-ca-2/
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow_point = 0, fast_point = 0;
        int nums_len = nums.size();
        int i = 0;
        while (fast_point < nums_len)
        {
            if (nums[i] == 0)
            {
                fast_point++;
            }
            else
            {
                nums[slow_point] = nums[fast_point];
                slow_point++;
                fast_point++;
            }
            i++;
        }
        int count = fast_point - slow_point;
        for (int i = count; i > 0; i--)
        {
            nums[nums_len-i]=0;
        }
    }
};
/*
*简洁的写法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        // 将slowIndex之后的冗余元素赋值为0
        for (int i = slowIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

作者：carlsun-2
链接：https://leetcode-cn.com/problems/move-zeroes/solution/283-yi-dong-ling-shuang-zhi-zhen-xiang-jie-by-ca-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
// @lc code=end
