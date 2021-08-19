/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

 

示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
示例 3：

输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==1)
        {
            return nums[0];
        }
        int left=0,right=nums_size-1;//左闭右闭区间
        int mid;
        while (left<right)//思路可以参考这个https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-5irwp/
        //主要就是画出三种可能的排列方式
        /*
        (1) 从低到高按顺序排列
        (2) 低高低高，类似闪电的形状
        (3) 前面按顺序排列最后骤降，即最小的元素被放在了最后
        然后发现只要将nums[mid]和nums[size-1]进行比较，即可以发现缩减搜索区间的规律
        */
        {
            mid=left+(right-left)/2;
            if(nums[mid]>nums[nums_size-1])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
            
        }
        return nums[right];

    }
};
int main()
{
    Solution *a=new Solution();
    vector<int> nums={3,4,5,1,2};
    a->findMin(nums);
    delete a;
    return 0;
}