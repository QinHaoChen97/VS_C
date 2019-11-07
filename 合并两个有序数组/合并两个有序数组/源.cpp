//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入:
//nums1 = [1, 2, 3, 0, 0, 0], m = 3
//nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {	//插入使用vector.insert(position,value),在vector的第position处插入value
		if(n==0)		
		{
			return;
		}
		if (m==0)
		{
			nums1 = nums2;
			return;
		}
		int j = 0;		//由于nums1和nums2都是有序排列，故nums2只需从上一次插入的位置开始比较即可
		for (int i = 0; i < n; i++)			//n个数需要插入		
		{		
			for (; j < nums1.size(); j++)	//与nums1中的数进行对比
			{	
				if (j==m)	//判断是否已经到达m+1的位置，是的话说明有两种情况1.剩余的nums2都大于nums1中的最大值，直接将剩余的nums2插入到num1后部 2.nums2第一个数小于nums1第一个数
				{
					for (int k = i; k < n; k++)		
					{	
						nums1.insert(nums1.begin()+m,nums2[i++]);
						m++;
						nums1.pop_back();
					}
					return ;			//做完剩余的插入后已经执行完毕，直接返回
				}
				if (nums2[0]<nums1[0])	//提前排除到上述提到的情况2
				{
					nums1.insert(nums1.begin(), nums2[0]);
					nums1.pop_back();
					m++;
					break;  
				}
				if(nums2[i] >= nums1[j] && nums2[i] < nums1[j+1])		//找到nums[i]插入的位置
				{				
					nums1.insert(nums1.begin()+j+1, nums2[i]);	//iterator insert(iterator it,const T& x):向量中迭代器指向元素前增加一个元素x
					nums1.pop_back();		//弹出一个nums1尾部的0,此处应该先插入后弹出
					m++;	//更新此时m的大小，也隐含的改变了j的初值
					break;
				}
			}
		}
	};
};
int main()
{
	Solution a;
	vector<int> nums1 = { 1, 0 };
	vector<int> nums2 = { 2 };
	a.merge(nums1, 1, nums2, 1);
	return 0;
}