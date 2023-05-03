// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem738.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string nstr=to_string(n);
        int nstr_len=nstr.size();
        if (nstr_len==1)
        {
            return n;
        }
        for (int i = nstr_len-1; i >=1 ; i--)
        {
            if (nstr[i]=='0')
            {
                while (i>=1 && nstr[i]=='0')
                {
                    nstr[i]='9';
                    i--;
                    //cout<<i<<endl;
                }
                nstr[i]-=1;
            }
            else if(nstr[i]<nstr[i-1])
            {
                nstr[i]='9';
                nstr[i-1]-=1; 
            }
            
        }
        return stoi(nstr);
    }
};
// @lc code=end

