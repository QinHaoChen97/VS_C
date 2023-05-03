/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> tmp = {a,b,c};
        sort(tmp.begin(), tmp.end());
        a = tmp[0];
        b = tmp[1];
        c = tmp[2];
        int max_moves  = c-a-2;
        int min_moves;
        if(a+1 == b && b+1 == c)
        {
            min_moves = 0;
        }
        else if(a+1 == b)
        {
            min_moves = 1;
        }
        else if(b+1 == c)
        {
            min_moves = 1;
        }
        else
        {
            if(b-a == 2 || c-b == 2)
            {
                min_moves = 1;
            }
            else
            {
                min_moves = 2;
            }
            
        }
        return {min_moves, max_moves};
    }
};
// @lc code=end

