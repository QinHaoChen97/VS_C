/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
//思路可以参照这里
//https://leetcode-cn.com/problems/find-k-closest-elements/solution/658-zhao-dao-kge-zui-jie-jin-de-yuan-su-eqmyd/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-k;
        int mid;
        while (left<right)
        {
            mid=left+(right-left)/2;
            if (x-arr[mid]>arr[mid+k]-x)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
        
    }
};
// @lc code=end

