/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
//https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/
// 先理解不带哈希表的版本再看这个版本会比较容易
// 这里利用哈希表可以实现查询复杂度为O(1)，所以总的时间复杂度是0(N)
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presum_count;
        presum_count.insert({0,1}); //前缀和为0的个数为1，比如空数组
        int presum=0; //前缀和
        int count=0; //统计满足条件的个数
        for (int i = 0; i < nums.size(); i++)
        {
            presum+=nums[i];
            if (presum_count.find(presum-k)!=presum_count.end())
            {
                count+=presum_count[presum-k];
            }
            presum_count[presum]+=1; //将前缀和存储到哈希表中
            
        }
        return count;
    }
};
// @lc code=end

