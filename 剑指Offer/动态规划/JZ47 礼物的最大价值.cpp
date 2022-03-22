//https://www.nowcoder.com/practice/2237b401eb9347d282310fc1c3adb134?tpId=13&tqId=2276652&ru=/practice/64b4262d4e6d4f6181cd45446a5821ec&qru=/ta/coding-interviews/question-ranking
//这道题应该是简单难度的
#include<vector>
#include<algorithm>
using std::vector;
using std::max;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        int row=grid.size();
        int colum=grid[0].size();
        vector<vector<int>> dp(row,vector<int>(colum,0));
        
        //初始化
        dp[0][0]=grid[0][0];
        for (int j = 1; j < colum; j++)
        {
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for (int i = 1; i < row; i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < colum; j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j]; //当前的最大值的递推公式
            }
            
        }
        return dp[row-1][colum-1];
        
        
    }
};