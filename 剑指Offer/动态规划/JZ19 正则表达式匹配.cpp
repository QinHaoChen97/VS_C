//https://www.nowcoder.com/practice/28970c15befb4ff3a264189087b99ad4?tpId=13&tqId=1375406&ru=/practice/9f3231a991af4f55b95579b44b7a01ba&qru=/ta/coding-interviews/question-ranking
/*
描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

数据范围:
1.str 可能为空，且只包含从 a-z 的小写字母。
2.pattern 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。
3. 0 <= str.length <= 20
4. 0 <= pattern.length <= 30

示例1
输入：
"aaa","a*a"
返回值：
true
说明：
中间的*可以出现任意次的a，所以可以出现1次a，能匹配上   

示例2
输入：
"aad","c*a*d"
返回值：
true
说明：
因为这里 c 为 0 个，a被重复一次， * 表示零个或多个a。因此可以匹配字符串 "aad"。
*/
#include<iostream>
#include<vector>
using std::vector;
using std::string;
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param str string字符串 
         * @param pattern string字符串 
         * @return bool布尔型
         */
        bool match(string str, string pattern) {
            // write code here
            int row=str.size();
            int colum=pattern.size();
            vector<vector<bool>> dp(row+1,vector<bool>(colum+1,false)); //dp[i][j]表示str[0~i-1]与str[0~j-1]是否匹配
            //初始化
            dp[0][0]=true;
            for (int j = 2; j <= colum; j+=2) // 初始化第一行
            {
                /* code */
                if (pattern[j-1]=='*')  
                {
                    dp[0][j]=dp[0][j-2];
                }
            }

            // 构造dp数组
            for (int i = 1; i <= row ; i++)
            {
                for (int j = 1; j <= colum; j++)
                {
                    if (pattern[j-1]=='.' || str[i-1]==pattern[j-1])    
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if (pattern[j-1]=='*')
                    {
                        //匹配1个字符
                        if (dp[i][j-1])
                        {
                            dp[i][j]=dp[i][j-1];
                        }
                        else if (j>=2 && dp[i][j-2]) //匹配0个字符
                        {
                            dp[i][j]=dp[i][j-2];
                        }
                        else if(i>=2 && j>=2) //i>=2是因为匹配多个字符说明i至少需要两个字符了
                        {
                            dp[i][j]=dp[i-1][j] && (str[i-1]==pattern[j-2] || pattern[j-2]=='.'); //匹配多个字符
                            //即需要看dp[i-1][j]能否满足匹配多个字符的条件
                            //再看当前的字符str[i-1]是否pattern[j-2]与相等，相等才能用*继续复制
                        }
                        
                        
                        
                    }
                    
                }
                
            }
            return dp[row][colum];
            
            

        }
    };