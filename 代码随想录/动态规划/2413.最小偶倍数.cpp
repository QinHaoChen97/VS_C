/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 *
 * [2413] 最小偶倍数
 */

// @lc code=start
#include<math.h>
using namespace std;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n/2.0 != ceil(n/2.0))
        {
            return 2*n;
        }
        return n;
    }
};
// @lc code=end

