/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int now_point = 0; //nowpoint为当前指向的位置
		if (nums.empty())
		{
			return 0;
		}
		int n = nums.size();
		for (int i = 0; i <n; i++)
		{
			if (nums[now_point]==val)
			{
				nums.erase(nums.begin() + now_point);
			}
			else
			{
				now_point++;
			}
		}
		return (int)nums.size();
	}
};
int main()
{
	vector<int> a = { 3,2,2,3 };
	Solution b;
	b.removeElement(a,3);
	cin.get();
}