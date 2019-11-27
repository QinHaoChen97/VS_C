//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。
//
//示例 1：
//
//输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶
//示例 2：
//
//输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
#include<iostream>
using namespace std;
//有了前面的基础，这道题较为简单了，用一位数组动态规划即可，每个位置存储能到达当前位置的方法数
//stair[m]表示m阶台阶能到达的方法数,起点为m=0,stair[0]=0,stair[1]=1，stair[2]=2;这三种情况不适用于下述的条件
/*
if(m>2)
	stair[m]=stair[m-1]+stair[m-2];//走一步能到达当前台阶的只有两种情况，距离一阶和距离两阶,到达当前台阶的方法只有从距离二阶台阶走1+1（等同于从距离一阶台阶处走1）
	//和从二阶台阶走2，所以实际上这两种情况是固定的，故到达当前台阶的方法为到达m-1阶台阶的方法和到达m-2阶台阶方法的总和！
*/
class Solution {
public:
	int climbStairs(int n) {
		if (n==0)
		{
			return 0;
		}
		else if (n==1)
		{
			return 1;
		}
		else if(n==2)
		{
			return 2;
		}
		else
		{
			int* stair = new int[n + 1];
			stair[0] = 0;
			stair[1] = 1;
			stair[2] = 2;
			for (int m = 3; m < n+1; m++)
			{
				stair[m] = stair[m - 1]  + stair[m - 2];
			}
			int sum = stair[n];
			delete[]stair;
			return sum;
		}
		
	}
};
int main()
{
	int n = 45;
	Solution test;
	test.climbStairs(n);
	cin.get();
}