/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
所能勾勒出的最大矩形面积，其面积为 10 个单位（中间的5,6  5*2=10 ）。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//使用单调栈
//核心的思想是以当前的柱子作为其中最短的柱子的时候其矩形的最长长度为多少
//简单举例
//[2,1,5,6]
//栈的变化为
/*
                                  1<2所以将2弹出，并且以其为当前最短的柱子计算矩形面积
								  能满足该条件的距离即为它到它在栈中下一个元素的距离，以其做为矩形的底
								                                                                            填充完后弹出
												6															此时能满足当前柱子为最短的距离为heights.size()-stack.(top-1)-1;
										   5    5                                                           注意heights.size为数组下标的最大值+1 ,充当了先前i的值
			2         2            1       1    1
   -1       -1        -1		  -1      -1   -1                                                            
*/ 
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n==0)
		{
			return 0;
		}
		if (n==1)
		{
			return heights[0];
		}
		stack<int> sta;
		int maxsquare = 0;
		sta.push(-1);
		for (int i = 0; i < n; i++)
		{
			while(sta.top()!=-1 && heights[sta.top()]>heights[i])
			{
				int mini = heights[sta.top()];
				sta.pop();
				maxsquare = max(maxsquare, (i - sta.top() - 1)*mini);
			}
			sta.push(i);
		}
		while (sta.top()!=-1)
		{
			int mini = heights[sta.top()];
			sta.pop();
			maxsquare = max(maxsquare, (n - sta.top() - 1)*mini);
		}
		return maxsquare;
	}
};
int main()
{

}