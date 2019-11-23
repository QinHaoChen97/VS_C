//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？
//
//说明：m 和 n 的值均不超过 100。
//
//示例 1 :
//
//输入: m = 3, n = 2
//	输出 : 3
//	解释 :
//	从左上角开始，总共有 3 条路径可以到达右下角。
//	1. 向右->向右->向下
//	2. 向右->向下->向右
//	3. 向下->向右->向右
//	示例 2 :
//
//输入: m = 7, n = 3
//	输出 : 28

#include<iostream>
using namespace std;
//杨辉三角解法
//迭代的动态规划也可以，但这道题感觉不是很合适
//杨辉三角
/*
m 1 2 3  4  5
n 1 1 1 1  1  1
2 1 2 3  4  5
3 1 3 6  10 15
4 1 4 10 20 35
5 1 5 15 35 70
*/
class Solution {
public:
	int uniquePaths(int m, int n) {  //m列n行
		int **nums;
		nums = new int*[n];		//自我的理解是  nums存放的是int*的地址  从这个地址开始分配n个存放int*类型的内存
		for (int i = 0; i < n; i++)
		{
			nums[i] = new int[m];   //nums[n]即*（nums+n）存放的是int的地址，从这个地址开始分配n个存放int类型的内存
		}

		//初始化动态二维数组nums[n][m];
		//初始化杨辉三角
		for (int i = 0; i < n; i++)
		{
			nums[i][0] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			nums[0][i] = 1;
		}
		for (int i = 1; i < n; i++)  //第一行已经事先放好了，从第二行开始
		{
			for (int j = 1; j < m; j++) //第一列已经事先放好了，从第二列开始
			{
				nums[i][j] = nums[i - 1][j] + nums[i][j - 1];  //从第二行第二列开始，一定不会越界
			}
		}
		return nums[n - 1][m - 1];
	}
};
int main()
{
	int m = 3,n = 2;
	Solution a;
	int b=a.uniquePaths(m, n);
	cout << b << endl;
	cin.get();
}