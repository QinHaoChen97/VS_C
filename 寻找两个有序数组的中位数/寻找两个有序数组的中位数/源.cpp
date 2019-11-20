//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//
//你可以假设 nums1 和 nums2 不会同时为空。
//
//示例 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
//示例 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是(2 + 3) / 2 = 2.5

//有点难 解法参考官方的解法https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu-b/
/*
* 1.首先，让我们在任一位置 i 将 A(长度为m) 划分成两个部分：
*            leftA            |                rightA
*   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
*
* 由于A有m个元素，所以有m + 1中划分方式(i = 0 ~ m)
*
* 我们知道len(leftA) = i, len(rightA) = m - i;
* 注意：当i = 0时，leftA是空集，而当i = m时，rightA为空集。
*
* 2.采用同样的方式，将B也划分为两部分：
*            leftB            |                rightB
*   B[0],B[1],...      B[j-1] |   B[j],B[j+1],...B[n - 1]
*  我们知道len(leftA) = j, len(rightA) = n - j;
*
*  将leftA和leftB放入一个集合，将rightA和rightB放入一个集合。再把这两个集合分别命名为leftPart和rightPart。
*
*            leftPart         |                rightPart
*   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
*   B[0],B[1],...      B[j-1] |  B[j],B[j+1],...B[n - 1]
*
*   如果我们可以确认：
*   1.len(leftPart) = len(rightPart); =====> 该条件在m+n为奇数时，该推理不成立
*   2.max(leftPart) <= min(rightPart);
*
*   median = (max(leftPart) + min(rightPart)) / 2;  目标结果
*
*   要确保这两个条件满足：
*   1.i + j = m - i + n - j(或m - i + n - j + 1)  如果n >= m。只需要使i = 0 ~ m，j = (m+n+1)/2-i =====> 该条件在m+n为奇数/偶数时，该推理都成立
*   2.B[j] >= A[i-1] 并且 A[i] >= B[j-1]
*
*   注意:
*   1.临界条件：i=0,j=0,i=m,j=n。需要考虑
*   2.为什么n >= m ? 由于0 <= i <= m且j = (m+n+1)/2-i,必须确保j不能为负数。
*
*   按照以下步骤进行二叉树搜索
*   1.设imin = 0,imax = m，然后开始在[imin,imax]中进行搜索
*   2.令i = (imin+imax) / 2, j = (m+n+1)/2-i
*   3.现在我们有len(leftPart) = len(rightPart)。而我们只会遇到三种情况：
*
*      ①.B[j] >= A[i-1] 并且 A[i] >= B[j-1]  满足条件
*      ②.B[j-1] > A[i]。此时应该把i增大。 即imin = i + 1;
*      ③.A[i-1] > B[j]。此时应该把i减小。 即imax = i - 1;
*
 */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		bool exchange = false;
		if (nums1.size()>nums2.size())	//保证条件m<=n; m=nums1.size(),n=nums2.size();因为这里是引用，所以最后最好是将两个数组调整回来
		{
			exchange = true;
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
		}
		int MIN = 0, MAX = nums1.size();
		int m = nums1.size(), n = nums2.size();
		int halflen = (m + n + 1) / 2;	//由i+j=m-i+n-j（m+n为偶数）或i+j=m-i+n-j+1（m+n为奇数个）得出，由于取整的特性，可以合并为一条
		while (MIN<=MAX)
		{
			int i = (MIN + MAX) / 2; //二分法，为了满足复杂度的要求
			int j = halflen - i;
			//满足条件一是左右两组长度相等，二是A[i-1]<=B[j],B[j-1]<A=[i]
			//下面列出所有的条件
			if (i>MIN && nums1[i-1]>nums2[j])	//这里前面可以写做i>0更好理解，因为是为了防止数组访问越界
				//因为j是由i推导来的，且m<=n,他们的关系式暗含了j<n的条件
			{
				//说明i太大，中位数应该在[MIN,i]的区间里
				MAX = i-1;
			}
			else if (i<MAX && nums2[j-1]>nums1[i])//同理这里可以写做i<m
				//同理暗含了j>0
			{
				//说明j太大了-->i太小，中位数应该在[i,MAX]的区间里
				MIN = i+1;
			}
			else//第三个集合即为满足题意的情况A[i-1]<=B[j],B[j-1]<A=[i]
			{
				int maxleft = 0;
				if (i==0)// nums1的左子集为空，那么只需满足A[i]>B[j-1],即B[j-1]=maxleft
				{
					maxleft = nums2[j - 1];
				}
				else if(j==0)
				{
					maxleft = nums1[i - 1];
				}
				else//正常情况下
				{
					maxleft = max(nums1[i - 1], nums2[j - 1]);
				}
				if ((m+n)%2==1)//m+n为奇数，说明此事maxleft即为中位数
				{
					if (exchange)	//避免修改原始数组
					{
						vector<int> temp = nums2;
						nums2 = nums1;
						nums1 = temp;
					}
					return maxleft;
				}
				else//否则需要将minright求出，中位数=(minright+maxleft)/2
				{
					int minright = 0;
					if (i==m)//nums1的右子集为空,自然此时minright=nums2[j]
					{
						minright = nums2[j];
					}
					else if (j==n)//nums2的右子集为空
					{
						minright = nums1[i];
					}
					else//正常情况，两者的右子集都不为空
					{
						minright = min(nums1[i], nums2[j]);
					}
					if (exchange)
					{
						vector<int> temp = nums2;
						nums2 = nums1;
						nums1 = temp;
					}
					return (double)(maxleft + minright) / 2; //注意这里要强制转型，否则C++的计算结果是int型，即/2会被去除掉小数部分
				}
			}
		}
		return 0.0; //由于题干要求至少有一个数组不为空，所以这里实际上不会运行到
	}
};
int main()
{
	vector<int> nums1 = { 1,2 }, nums2 = { 3,4 };
	Solution A;
	A.findMedianSortedArrays(nums1, nums2);
	cin.get();
}