// https://www.nowcoder.com/practice/2a49359695a544b8939c77358d29b7e6?tpId=13&tqId=1517966&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//回溯法
#include <vector>
#include <string>
using std::string;
using std::vector;
class Solution
{
    vector<vector<char>> m;
    string target;
    string ans;
    vector<vector<bool>> used;
    int row;
    int col;

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char>> &matrix, string word)
    {
        row = matrix.size();
        if (row == 0)
        {
            return false;
        }
        col = matrix[0].size();
        m = matrix;
        target = word;
        ans.clear();
        used = vector<vector<bool>>(row, vector<bool>(col, false));
        int pos = 0; //统计现在在匹配第几个字母
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (backtracking(i, j, pos))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool backtracking(int i, int j, int &pos)
    {

        if (target == ans)
        {
            return true;
        }
        if (i >= 0 && i < row && j >= 0 && j < col) // i,j的是否满足边界条件
        {
            if (used[i][j] == false && m[i][j] == target[pos])
            {
                ans += target[pos];
                pos++; //下一个位置
                used[i][j] = true;
                bool b = backtracking(i + 1, j, pos) || backtracking(i - 1, j, pos) || backtracking(i, j - 1, pos) ||
                         backtracking(i, j + 1, pos);
                //回溯
                ans.pop_back();
                pos--;
                used[i][j] = false;
                return b;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        // if (pos==target.size())  不需要对长度进行判断，因为是匹配当前字符才会继续进行回溯
        // {
        //     return false;
        // }
    }
};