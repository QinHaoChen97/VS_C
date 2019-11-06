#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//双指针法
//l指向容器左挡板，r指向容器的右挡板
//双指针法正确性的证明https://leetcode-cn.com/problems/container-with-most-water/solution/shuang-zhi-zhen-fa-zheng-que-xing-zheng-ming-by-r3/
//容器面积area=（j-i)*min(i,j)
class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0, r = height.size() - 1;		//左右挡板，注意size返回的是个数不是下标，要减去1
		int maxarea=0;//用于存放最大盛水面积
		int area = 0;//临时存放面积
		for (int i = 0; i < int(height.size() - 2); i++)		//假设有N个数据，需要移动N-2次,在下面改变r，这上面由用r做限制，傻逼！
		{
			if (height[l] >= height[r])		//不要忽略两个挡板一样高的情况
			{
				area = (r - l)*height[r];	//以较低的挡板为基准
				r--;//右挡板向左移动
			}
			else
			{
				area = (r - l)*height[l];
				l++;//左挡板向右移动
			}
			if (area>maxarea)
			{
				maxarea = area;
			}
		}
		//最后一次移动后的数据没有计算，在这里补上，此时他的宽度必定为1，只由俩挡板中较短的决定面积
		area = min(height[l], height[r]);
		if (area>maxarea)
		{
			maxarea = area;
		}
		return maxarea;
	}
};
int main()
{
	Solution a;
	vector<int> b = { 1, 3, 2, 5, 25, 24, 5 };
	a.maxArea(b);
	int c;
	cin >>c ;
}