// https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=13&tqId=1024831&ru=/practice/48d2ff79b8564c40a50fa79f9d5fa9c7&qru=/ta/coding-interviews/question-ranking
#include <string>
#include <vector>
using std::string;
using std::vector;
// https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=13&tqId=1024831&ru=/practice/48d2ff79b8564c40a50fa79f9d5fa9c7&qru=/ta/coding-interviews/question-ranking
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution
{
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums)
    {
        // write code here
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        if (len == 1)
        {
            if (nums == "0")
            {
                return 0;
            }

            return 1;
        }

        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= len; i++)
        {
            if (nums[i - 1] == '0')  //注意字符串有一位移位，要减一
            {
                if (nums[i - 2] == '0' || nums[i - 2] > '2')
                {
                    return 0;
                }
                else
                {
                    dp[i] = dp[i - 2];
                }
                continue;
            }

            if (nums[i - 2] == '0')
            {
                dp[i] = dp[i - 1];
            }
            else if (nums[i - 2] == '1' || (nums[i - 2] == '2' && nums[i - 1] <= '6'))
            {
                dp[i] = dp[i - 2] + dp[i - 1];
            }
            else // nums[i-1]>2
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len];
    }
};