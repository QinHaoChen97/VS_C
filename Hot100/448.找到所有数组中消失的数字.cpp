// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem448.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
//利用nums做原地算法
//https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-d-mabl/
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 时间复杂度O（n）的话不能使用排序算法
        int n=nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            nums[(nums[i]-1)%n]+=n; //注意先取余再减1和先减1再取余不是完全一样的
            //当nums[i]==n时，前者会得到-1，使vector的读取出错
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]<=n)
            {
                ans.push_back(i+1);
            }
            
        }
        return ans;
        
    }
};
// @lc code=end

