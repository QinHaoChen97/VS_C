/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
  ]
  输出: 7
  解释: 因为路径 1→3→1→1→1 的总和最小。
*/
#include<iostream>
#include<vector>
using namespace std;
//动态规划，nums[m-1][n-1]存放到达当前路径的最短距离
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m==0)
		{
			return 0;
		}
		int n = grid[0].size();
		if (n==0)
		{
			return 0;
		}

		int**nums = new int*[m];
		for (int i = 0; i < m; i++)
		{
			nums[i] = new int[n];
		}

		//初始化第一行和第一列
		nums[0][0] = grid[0][0];
		//第一行
		for (int i = 1; i < n; i++)
		{
			nums[0][i] = grid[0][i] + nums[0][i - 1]; //因为只能往右往下走，所以到达当前位置的路径只有左方
		}
		//第一列
		for (int i = 1; i < m; i++)
		{
			nums[i][0] = grid[i][0] + nums[i - 1][0]; //同理，路径只有上方
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				nums[i][j] = grid[i][j] + (nums[i - 1][j] > nums[i][j - 1] ? nums[i][j - 1] : nums[i - 1][j]); //到nums[i][j]的最小距离等于当前位置的距离加上其上方和左方中较小的一个
			}
		}
		return nums[m - 1][n - 1];
	}
};
int main()
{
	vector<vector<int>> a = { {1, 3, 1},{1, 5, 1 }, { 4, 2, 1} };
	Solution test;
	test.minPathSum(a);
	cin.get();
}