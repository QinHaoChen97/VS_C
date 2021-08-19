/*
峰值元素是指其值大于左右相邻值的元素。

给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

 

示例 1：

输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。
示例 2：

输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
 

提示：

1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==1)
        {
            return 0;
        }
        if (nums_size==2)
        {
            return nums[0]>nums[1]?0:1;
        }
        int left=0,right=nums_size;
        int mid;
        while (left<right)
        {
            mid=left+(right-left)/2;
            if (mid!=0 && nums[mid]<nums[mid-1])
            {
                right=mid;
            }
            else if (mid!=(nums_size-1) && nums[mid]<nums[mid+1])
            {
                left=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return right;//这一步感觉不起作用,因为while循环中一定可以return了，但是leetcode里面不允许这么写
    }
};
//更简单的写法
class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
int main()
{
    Solution a;
    vector<int> b={1,2,3,4,3};
    a.findPeakElement(b);
    return 0;
}