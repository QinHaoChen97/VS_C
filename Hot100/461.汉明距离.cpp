// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem461.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int nor=x ^ y; //异或
        int z=1;
        int count=0;
        while (nor != 0)
        {
            if (nor & 1 == 1)
            {
                count++;
            }
            nor=nor>>1; //右移
        }
        return count;
    }
};
// @lc code=end

