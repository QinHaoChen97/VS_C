/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> ans;
    int s_len;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        ans.clear();
        s_len = s.size();
        if (s_len == 1)
        {
            return { {s} };
        }
        backtracking(0, s);
        return ans;
    }
    void backtracking(int pos, const string& s)
    {
        if (pos >= s_len)  //此时已经找到最后一个回文字符串，肯定会到达这一条件，因为最后一个字符
        //可以单独组成回文字符串
        {
            if (!path.empty())
            {
                ans.push_back(path);
            }
            return;
        }
        for (int i = 1; i <= s_len - pos; i++) //从当前点开始往后分割
        {
            string sub_s(s.begin() + pos, s.begin() + pos + i); //截取字符串
            if (judge(sub_s))
            {
                path.push_back(sub_s);
                backtracking(pos + i, s);
                path.pop_back();
            }
            else //不是回文串，继续往前找
            {
                continue;
            }
        }
    }
    bool judge(const string& s) //判断是否是回文
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution a;
    string s = "aab";
    vector<vector<string>> ans=a.partition(s);
    std::cin.get();

}
// @lc code=end

