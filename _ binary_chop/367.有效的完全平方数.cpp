// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem367.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==0)
        {
            return true;
        }
        
        int left=1,right=num;
        float mid,result;
        while (left<=right)
        {
            mid=left+(right-left)/2;
            result=float(num)/mid;
            if (result==mid)
            {
                return true;
            }
            else if (result<mid)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
            
        }
        return NULL;  
    }
};
// @lc code=end

