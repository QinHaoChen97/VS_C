/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int row = 0; row < n/2; row++)
        {
            for (int col = 0; col < (n+1)/2; col++)
            {
                int temp=matrix[row][col];
                matrix[row][col]=matrix[n-col-1][row];
                matrix[n-col-1][row]=matrix[n-row-1][n-col-1];
                matrix[n-row-1][n-col-1]=matrix[col][n-row-1];
                matrix[col][n-row-1]=temp;
            }
            
        }
        return;
        
    }
};

//https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/
//其实旋转了90度，那么四次之后360度必然就是有一个循环了
//剩下的就是分割问题，参考题解里的分割方法
// @lc code=end

