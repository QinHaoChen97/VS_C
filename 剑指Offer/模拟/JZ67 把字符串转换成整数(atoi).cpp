#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int StrToInt(string s)
    {
        int max_len = 10; //超过这个长度肯定会溢出
        int count_len = 0;
        string ans;
        bool positive = true;
        int i = 0;
        int s_len = s.size();
        for (i; i < s_len; i++) //跳过空格
        {
            if (s[i] != ' ')
            {
                break;
            }
        }
        if (s[i] == '-') //判断是否有符号位
        {
            positive = false;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        for (i; i < s_len; i++) //去掉前面的0
        {
            if (s[i]!='0')
            {
                break;
            }
            
        }
        
        for (i; i < s_len; i++)
        {
            if(s[i]>='0' &&  s[i]<='9')
            {
                ans+=s[i];
                count_len++;
                if (count_len>max_len)
                {
                    if(!positive)
                    {
                        return INT_MIN;
                    }
                    else
                    {
                        return INT_MAX;
                    }
                }
                
            }
            else
            {
                break;
            }
            
        }

        if (ans.size() == 0)
        {
            return 0;
        }
        else
        {
            long int num = 0;
            for (const auto &ch : ans)
            {
                num = num * 10 + (ch - '0');
            }
            if (!positive)
            {
                num = -num;
                if (num < INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
            {
                if (num > INT_MAX)
                {
                    return INT_MAX;
                }
            }
            return num;
        }
    }
};