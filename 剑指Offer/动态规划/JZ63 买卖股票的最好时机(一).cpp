// https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec?tpId=13&tqId=625&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 这道题也可以用动规，牺牲时间复杂度
#include <vector>
#include <limits.h>
using std::vector;
class Solution
{
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        // write code here
        int pri_len = prices.size();
        if (pri_len == 0)
        {
            return 0;
        }
        int min_pri = prices[0];
        int max_profit = 0;
        for (int i = 0; i < pri_len; i++)
        {
            int profit = prices[i] - min_pri;
            if (profit > max_profit)
            {
                max_profit = profit;
            }
            if (prices[i] < min_pri)
            {
                min_pri = prices[i];
            }
        }
        return max_profit;
    }
};