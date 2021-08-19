// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem215.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
/*
快速选择一般用于求解 k-th Element 问题，可以在 O(n) 时间复杂度，O(1) 空间复杂度完成求
解工作。快速选择的实现和快速排序相似，不过只需要找到第 k 大的枢（pivot）即可，不需要对
其左右再进行排序。与快速排序一样，快速选择一般需要先打乱数组，否则最坏情况下时间复杂
度为 O(n2)，我们这里为了方便省略掉了打乱的步骤。
*/
    int findKthLargest(vector<int>& nums, int k) {
        //利用快速排序做辅助，但不用完成整个序列的排序
        int l=0,r=nums.size()-1,target=nums.size()-k;//target为k对应从小到大排序的位置
        int pos=quicksort(nums,l,r);
        while (pos!=target)
        {
            if (pos>target)
            {
                r=pos-1;
                pos=quicksort(nums,l,r);
            }
            else if (pos<target)
            {
                l=pos+1;
                pos=quicksort(nums,l,r);
            }
        }
        return nums[pos];       
    }
    //快速排序辅助函数
    int quicksort(vector<int>& nums,int l,int r)
    {
        int piovt=nums[l];//基准
        //这个步骤手动画一下会很清晰，就是将小于基准的数移动基准左边，反之移动到右边
        while (l<r)
        {
            while (l<r && nums[r]>=piovt)
            {
                r--;
            }
            nums[l]=nums[r];
            while (l<r && nums[l]<=piovt)
            {
                l++;
            }
            nums[r]=nums[l];  
        }
        nums[l]=piovt; 
        return l;//pos==l==r,end condiction:l==r;  
    }
};



class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //利用stl:sort
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }
private: 
    static bool compare(int a,int b){
        return a>b?true:false;
    }   
};
// @lc code=end

