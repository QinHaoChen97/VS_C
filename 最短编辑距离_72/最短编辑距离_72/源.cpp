//给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//删除一个字符
//替换一个字符
//示例 1 :
//
//输入: word1 = "horse", word2 = "ros"
//	输出 : 3
//	解释 :
//	horse->rorse(将 'h' 替换为 'r')
//	rorse->rose(删除 'r')
//	rose->ros(删除 'e')
//	示例 2 :
//
//	输入 : word1 = "intention", word2 = "execution"
//	输出 : 5
//	解释 :
//	intention->inention(删除 't')
//	inention->enention(将 'i' 替换为 'e')
//	enention->exention(将 'n' 替换为 'x')
//	exention->exection(将 'n' 替换为 'c')
//	exection->execution(插入 'u')
#include<iostream>
#include<algorithm>  //Min
using namespace std;
//参考了以下解法
/*
思路：
动态规划：
dp[i][j] 代表 word1 到 i 位置转换成 word2 到 j 位置需要最少步数

所以，

当 word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]； //即不需要多余的步骤只需要在原来的基础上"添加"这个字符就好了，但实际上这个字符就是已经拼接好的，所以这个步骤不需要执行

当 word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 //假设此时不相等，由于前面的操作我们只需要在先前的操作中任选一种操作再进行一步一定能使两个字符串相等
//既然三种方法都再通过一步便可以得到正确的结果，那么我们选择其中需要的方法总数最少的来加一

其中，dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作。

注意，针对第一行，第一列要单独考虑，我们引入 '' 下图所示：
		‘’ r o s    
	‘’ 0   1 2 3
	 h   1
	 o   2
	 r   3
	 s	 4
	 e	 5

第一行，是 word1 为空变成 word2 最少步数，就是插入操作

第一列，是 word2 为空，需要的最少步数，就是删除操作

作者：powcai
链接：https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		if (m==0)
		{
			return n;
		}
		else if (n==0)
		{
			return m;
		}
		else
		{
			int **dp = new int*[m + 1];
			for (int i = 0; i < m+1; i++)//构建m+1行，n+1列二维数组，加一是因为''（空字符）
			{
				dp[i] = new int[n + 1];
			}
			//为''一行初始化
			for (int  i = 0; i < m+1; i++) //当word2为空字符时，只需要删除
			{
				dp[i][0] = i;
			}
			for (int  j = 0;  j <n+1;  j++)//当word1为空字符时，只需要添加
			{
				dp[0][j] = j;
			}
			for (int i = 1; i < m+1; i++)
			{
				for (int j = 1; j < n+1; j++)
				{
					if (word1[i-1]==word2[j-1]) //注意字符串是要从首位开始比较，所以应当是i-1,j-1
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = dp[i - 1][j - 1] > dp[i - 1][j] ? (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]) : (dp[i - 1][j - 1] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j - 1]);
						dp[i][j]++;
					}
				}
			}
			int nums = dp[m][n];
			delete[]dp;
			return nums;
		}
	}
};
int main()
{

}