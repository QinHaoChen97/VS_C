// https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=23460&ru=/practice/2a49359695a544b8939c77358d29b7e6&qru=/ta/coding-interviews/question-ranking
#include <vector>
using std::vector;
class Solution
{
    int ans;
    int _threshold;

public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold == 0)
        {
            return 1;
        }
        ans = 0;
        //遍历矩阵
        vector<vector<int>> m(rows, vector<int>(cols, 0)); // 0代表未访问
        _threshold = threshold;
        dfs(0, 0, m, rows, cols);
        return ans;
    }
    int value(int num)
    {
        int sum = 0;
        while (num != 0) //算两个的值的部分可以剪枝，根据上一个计算结果来得到
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    void dfs(int i, int j, vector<vector<int>> &m, const int &rows, const int &cols)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || m[i][j] == 1)
        {
            return;
        }
        int i_value = value(i);
        int j_value = value(j);
        if (i_value + j_value <= _threshold)
        {
            ans++;
            m[i][j] = 1; // 标记已经访问过
            dfs(i + 1, j, m, rows, cols);
            dfs(i - 1, j, m, rows, cols);
            dfs(i, j + 1, m, rows, cols);
            dfs(i, j - 1, m, rows, cols);
            //无需回溯
        }
        else
        {
            return;
        }
    }
};