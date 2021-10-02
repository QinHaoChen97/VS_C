// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem395.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int length = s.size();
        unordered_map<char, int> count;
        //字符数统计
        for (auto ch : s)
        {
                count[ch]++;
        }
        vector<int> splits;
        for (int i=0; i < length; i++)
        {
            if (count[s[i]] < k)
            {
                splits.push_back(i);
            }
        }
        if (splits.empty())
        {
            return length;
        }
        int left=0;
        int res=0;
        for (int i = 0; i < splits.size(); i++)
        {
            int len=splits[i]-left;
            if (len>=k && len>res)
            {
                res=max(res,longestSubstring(s.substr(left,len),k));
            }
            left=splits[i]+1;
            
        }
        if (left<length-1)
        {
            res=max(res,longestSubstring(s.substr(left),k));
        }
        return res;
        
    }

};

/*
class Solution {
public:
//滑动窗口法
//https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/zhi-shao-you-kge-zhong-fu-zi-fu-de-zui-c-o6ww/
    int longestSubstring(string s, int k) {
        int ret = 0;
        int n = s.length();
        //这里当然可以先遍历一遍字符串得到s种最多有多少种字符s_cnt，写成t<=s_cnt
        vector<int> s_kind(26,0);
        int s_cnt=0;
        for(auto i:s)
        {
            if(s_kind[i-'a']==0)
            {
                s_cnt++;
                s_kind[i-'a']=1;
            }
        }
        for (int t = 1; t <= s_cnt; t++) {
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int tot = 0;//字符串的种类
            int less = 0;//字符出现个数没满足k的个数
            while (r < n) {
                cnt[s[r] - 'a']++;//统计当前字符串某个字符出现的频次
                if (cnt[s[r] - 'a'] == 1) {
                    tot++;
                    less++;//存在不满足k次的字符的个数
                }
                if (cnt[s[r] - 'a'] == k) {
                    less--;//满足k次，--
                }

                while (tot > t) {//左移
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s[l] - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    l++;
                }
                if (less == 0) {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
};
*/
// @lc code=end
