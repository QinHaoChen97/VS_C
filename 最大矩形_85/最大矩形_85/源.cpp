/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]
]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//利用84题的原理，从每一行往上看，那么连着的1就相当于是柱子的高度，只需一行一行求出最大值即可
//如
/*
   1 0 1 0 0          1 0 1 0 0          1 0 1 0 0
                      1 0 1 1 1          1 0 1 1 1
					                     1 1 1 1 1
*/
class Solution {
public:
	int largestRectangleArea(int heights[],int n) {  //84题的算法,不过需要修改传入的值
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return heights[0];
		}
		stack<int> sta;
		int maxsquare = 0;
		sta.push(-1);
		for (int i = 0; i < n; i++)
		{
			while (sta.top() != -1 && heights[sta.top()]>heights[i])
			{
				int mini = heights[sta.top()];
				sta.pop();
				maxsquare = max(maxsquare, (i - sta.top() - 1)*mini);
			}
			sta.push(i);
		}
		while (sta.top() != -1)
		{
			int mini = heights[sta.top()];
			sta.pop();
			maxsquare = max(maxsquare, (n - sta.top() - 1)*mini);
		}
		return maxsquare;
	}
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m==0)
		{
			return 0;
		}
		int n = matrix[0].size();
		if (n==0)
		{
			return 0;
		}

		int **nums = new int*[m];
		for (int i = 0; i < m; i++)
		{
			nums[i] = new int[n];
		}
		for (int i = 0; i < m; i++)   //初始化成类似84题的柱状图
		{
			for (int j = 0; j < n; j++)
			{
				int k = i;
				nums[i][j] = 0;
				while (matrix[k][j]=='1')  //判断当前列连续1的高度
				{
					nums[i][j]++;
					if (k!=0)  //
					{
						k--;
					}
					else
					{
						break;
					}
				}
			}
		}

		int maxsquaretanguler = 0;
		for (int i = 0; i < m; i++)   //有m行需要求出m个最大值
		{
			maxsquaretanguler = max(maxsquaretanguler, largestRectangleArea(nums[i],n));
		}
		return maxsquaretanguler;
	}
};
int main()
{
	vector<vector<char>> a = { {"0","1"} };
	Solution test;
	int b=test.maximalRectangle(a);
	cin.get();
}