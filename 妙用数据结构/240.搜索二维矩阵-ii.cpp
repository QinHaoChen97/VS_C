// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem240.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0,right=matrix[0].size()-1;
        int end_right=right;
        for (int i = 0; i < matrix.size(); i++)
        {
            right=end_right;
            left=0;
            while (left<right)
            {
                int mid=left+(right-left)/2;
                if (matrix[i][mid]==target)
                {
                    return true;
                }
                else if (matrix[i][mid]>target)
                {
                    right=mid-1;
                    end_right=right;//去掉右半边
                }
                else
                {
                    //martix[i][mid]<target
                    left=mid+1;
                }
                
                
            }
            //left==might
            if (matrix[i][left]==target)
            {
                return true;
            }
            
        }
        return false;
        
        
    }
};
// @lc code=end

