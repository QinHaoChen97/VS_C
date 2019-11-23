//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//示例 :
//
//输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	输出 : 6
//	解释 : 连续子数组 [4, -1, 2, 1] 的和最大，为 6。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/maximum-subarray
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n==0)
		{
			return -1;
		}
		if (n==1)
		{
			return nums[0];
		}
		int headpoint = 0;//指向当前子数组的头
		int nextpoint = 1;//指向下一个要添加的数组元素
		int maxnums = nums[0];//用于存储最大子数组的和
		int nowseg = nums[0];//当前子数组的和
		while (nextpoint!=n)
		{
			if (nowseg<0)	
			{
				nowseg -= nums[headpoint];  //可以优化为nowseg=nums[nextpoint];
											//nextpoint++							
				headpoint++;
				if (nowseg>maxnums && headpoint!=nextpoint)		//每次改变nowseg都应判断最大子数组和是否改变,除非此时子数组为空
				{
					maxnums = nowseg;
				}
			}
			else//若是子数组大于等于0，则将新元素合并进来
			{
				nowseg += nums[nextpoint];
				if (nowseg>maxnums)
				{
					maxnums = nowseg;
				}
				nextpoint++;
			}
		}
		return maxnums;
	}
};

//上面这种逻辑还不是很好 参考这个
//动态规划的是首先对数组进行遍历，当前最大连续子序列和为 sum，结果为 ans

//如果 sum > 0，则说明 sum 对结果有增益效果，则 sum 保留并加上当前遍历数字
//如果 sum <= 0，则说明 sum 对结果无增益效果，需要舍弃，则 sum 直接更新为当前遍历数字(这一步是对上面nowseg<0中的执行语句的优化版，因为上面的操作等同于减去nums[headpoint]之后nowseg
//大于0，即nums[headpoint]一定是负数且绝对值大于后面的子数组和，既然这样何不一开始就不要将他添加入子数组中）

//每次比较 sum 和 ans的大小，将最大值置为ans，遍历结束返回结果
//时间复杂度：O(n)O(n)

