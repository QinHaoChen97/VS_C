/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
#include <unordered_set>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> x_power;
        vector<int> y_power;
        unordered_set<int> ans;
        int i = 0;
        while (true)
        {
            if(x == 1)
            {
                x_power.emplace_back(1);
                break;
            }
            int tmp = pow(x,i);
            if(tmp < bound) //另一个一定大于等于1，所以等于的情况可以不考虑
            {
                x_power.emplace_back(std::move(tmp));
            }
            else
            {
                break;
            }
            i++;
        }
        i = 0;
        while (true)
        {
            if(y == 1)
            {
                y_power.emplace_back(1);
                break;
            }
            int tmp = pow(y,i);
            if(tmp < bound) //另一个一定大于等于1，所以等于的情况可以不考虑
            {
                y_power.emplace_back(std::move(tmp));
            }
            else
            {
                break;
            }
            i++;
        }
        int x_len = x_power.size();
        int y_len = y_power.size();
        for (int i = 0; i < x_len; i++)
        {
            for (int j = 0; j < y_len; j++)
            {
                int tmp = x_power[i]+y_power[j];
                if(tmp <= bound)
                {
                    ans.insert(std::move(tmp));
                }
                else
                {
                    break;
                }
                
            }
            
        }
        return vector<int>(ans.begin(),ans.end());
    }
};
// @lc code=end

