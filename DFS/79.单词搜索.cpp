// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem79.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> used; //不允许重复使用，所以需要一个矩阵来打标记
    string path = "";
    int m, n;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size(); //1 <= m, n <= 6
        n = board[0].size();
        used = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(board, word, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(const vector<vector<char>> &board, const string &word, int i, int j)
    {
        if (i >= 0 && i < m && j >= 0 && j < n)
        {
            if (used[i][j] == 1)
            {
                return false;
            }
            //剪枝
            if (board[i][j]!=word[path.size()])//如果当前字符对不上，就没必要继续往下走了
            {
                return false;
            }
            
            path += board[i][j];
            used[i][j] = 1;
            if (path.size() == word.size())
            {
                if (path == word)
                {
                    path.pop_back();//对称
                    return true;
                }
                path.pop_back(); //回溯
                used[i][j] = 0;
                return false;
            }
            //否则还需要继续添加字符，向上下左右四个方向搜索
            bool judge=dfs(board, word, i, j + 1)+dfs(board, word, i - 1, j)+dfs(board, word, i + 1, j)+dfs(board, word, i, j - 1);
            path.pop_back();
            used[i][j] = 0;
            return judge;
        }
        return false;
    }
};
// @lc code=end
