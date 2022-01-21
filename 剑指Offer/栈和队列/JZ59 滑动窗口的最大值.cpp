// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=23458&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//单调队列
// https://blog.nowcoder.net/n/070e0808332c45078c7a128acb89141a
#include <vector>
#include <deque>
#include <limits.h>
using std::deque; //因为需要对队列尾部进行操作
using std::vector;
class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        typedef int pos;
        //退化情况
        int num_len = num.size();
        if (num_len == 0 || size == 0 || size > num_len)
        {
            return {};
        }
        else if (num_len == size)
        {
            int maxnum = INT_MIN;
            for (const auto &n : num)
            {
                if (maxnum < n)
                {
                    maxnum = n;
                }
            }
            return {maxnum};
        }
        //非退化情况
        deque<pos> q;
        vector<int> ans;
        for (int i = 0; i < size; i++) //第一个区间
        {
            process_deque(q, num, i);
        }
        int start = 0, end = size - 1;
        for (end = size; end < num_len; end++)
        {
            ans.push_back(num[q.front()]);
            process_deque(q, num, end);
            start++;
            if (start > q.front())
            {
                q.pop_front();
            }
        }
        //最后一个区间的最大值还未存入
        ans.push_back(num[q.front()]);
        return ans;
    }
    void process_deque(deque<int> &q, const vector<int> &num, int i)
    {
        if (q.empty())
        {
            q.push_back(i);
        }
        else
        {
            while (!q.empty() && num[q.back()] <= num[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
    }
};