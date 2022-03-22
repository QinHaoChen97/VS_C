#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        if (row == 0)
        {
            return {};
        }
        if (row == 1)
        {
            return matrix[0];
        }

        int column = matrix[0].size();
        vector<int> ans;
        // if (column == 1)
        // {
        //     for (int i = 0; i < row; i++)
        //     {
        //         ans.push_back(matrix[i][0]);
        //     }
        //     return ans;
        // }

        int start_row = 0, end_row = row - 1;
        int start_column = 0, end_column = column - 1;

        while (start_row < end_row && start_column < end_column)
        {
            for (int i = start_column; i <= end_column; i++)
            {
                ans.push_back(matrix[start_row][i]);
            }
            for (int i = start_row + 1; i <= end_row - 1; i++)
            {
                ans.push_back(matrix[i][end_column]);
            }
            for (int i = end_column; i >= start_column; i--)
            {
                ans.push_back(matrix[end_row][i]);
            }
            for (int i = end_row - 1; i >= start_row + 1; i--)
            {
                ans.push_back(matrix[i][start_column]);
            }
            start_row++;
            start_column++;
            end_row--;
            end_column--;
        }
        if (start_row == end_row) //如果还剩下一行没读取
        {
            for (int i = start_column; i <= end_column; i++)
            {
                ans.push_back(matrix[start_row][i]);
            }
        }
        else if (start_column==end_column)
        {
            for (int i = start_row; i <= end_row; i++)
            {
                ans.push_back(matrix[i][start_column]);
            }
            
        }

        return ans;
    }
};