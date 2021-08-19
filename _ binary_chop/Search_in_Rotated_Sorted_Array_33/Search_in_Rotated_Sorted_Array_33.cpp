/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //找到扭转的位置
        int nums_size=nums.size();
        int n=0;
        for (int i = 0; i < nums_size-1; i++)//size()-1是为了防止i+1访问到数组外
        {
            if (nums[i]>nums[i+1])
            {
                n=nums_size-(i+1);
            }
        }
        int l=0,r=nums_size-1;//左闭右闭区间
        int mid,visit;//在mid和实际访问的地址visit之间做一个映射
        while (l<=r)
        {
            mid=l+(r-l)/2;
            if(mid>=n)
            {
                visit=mid-n;
            }
            else
            {
               visit=(mid+n)%nums_size;
            }
            if (nums[visit]==target)
            {
                return visit;
            }
            else if(nums[visit]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution a;
    vector<int> b={3,5,1};
    int poi=a.search(b,5);
    return 0;
}