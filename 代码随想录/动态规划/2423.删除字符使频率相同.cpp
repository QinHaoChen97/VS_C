/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
 */

// @lc code=start
#include <string>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool equalFrequency(string word)
    {
        int len = word.size();
        if (len == 2)
        {
            return true;
        }
        vector<int> count(26, 0);
        int maxcount = 0;
        for (int i = 0; i < len; i++)
        {
            count[word[i] - 'a']++;
            maxcount = max(maxcount, count[word[i] - 'a']);
        }
        if (maxcount == 1)
        {
            return true;
        }
        int first_value = -1;
        bool first_flag = false;
        int second_value = -1;
        bool second_flag = false;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 0)
            {
                continue;
            }
            if (first_value == -1)
            {
                first_value = count[i];
            }
            else if (first_value == count[i])
            {
                first_flag = true;
            }
            else if (second_value == -1)
            {
                second_value = count[i];
            }
            else if (count[i] == second_value)
            {

                second_flag = true;
            }
            else
            {
                return false;
            }
        }
        if (first_flag && second_flag) // 都重复出现两次以上
        {
            return false;
        }
        if (second_value == -1) // 所有的字母出现的次数都相同
        {
            if (first_flag) // 只有一个字母还是有多个字母
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        // first_value != -1 && second_value != -1

        if (first_flag == false && first_value == 1)
        {
            return true;
        }
        if (second_flag == false && second_value == 1)
        {
            return true;
        }
        if (first_flag == true)
        {
            if (first_value > second_value)
            {
                return false;
            }
        }
        if (second_flag == true)
        {
            if (second_value > first_value)
            {
                return false;
            }
        }
        if (abs(second_value - first_value) != 1)
        {
            return false;
        }
        return true;
    }
};
// int main()
// {
//     Solution a;
//     a.equalFrequency("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

// }
// @lc code=end
