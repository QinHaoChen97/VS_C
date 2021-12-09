// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem581.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
#include<vector>
#include<map>
#include<limits.h>
using std::map;
using std::vector;
//O(n)的算法，将nums[i]分段，可以找出规律性
//https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/si-lu-qing-xi-ming-liao-kan-bu-dong-bu-cun-zai-de-/.


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        typedef int pos;
        map<int,pos> m;
        int left=INT_MAX,right=0;
        int max_nums=INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i])==m.end())
            {
                m[nums[i]]=i; //记录当前的数出现的最左的位置
            }
            if (nums[i]>max_nums)
            {
                max_nums=nums[i];
            }
            else if (nums[i]==max_nums)
            {
                continue;
            }
            else
            {
                //找到最左边的大于你本身的数
                for (int j = nums[i]+1; j <= max_nums ; j++)
                {
                    auto it=m.find(j);
                    if (it!=m.end())
                    {
                        left=(it->second<left)?it->second:left;
                        right=i;
                        break;
                    }
                }
                
            }
            
            
            
        }
        return left==INT_MAX?0:right-left+1;
        
        
    }
};
// @lc code=end

