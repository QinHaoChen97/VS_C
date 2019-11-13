//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//示例 1 :
//
//给定数组 nums = [1, 1, 2],
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//
//你不需要考虑数组中超出新长度后面的元素。
//示例 2 :
//
//给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//
//你不需要考虑数组中超出新长度后面的元素。
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {		//注意这是个排序数组，如果不是的话那么就要先进行排序了，但这不满足题目原地算法的要求了，应该是因为这样所以给了一个排序好的数组
		int position, mov_point;//双指针，一个指向下一个需要被修改的值，一个移动去寻找新出现的数字
		if (nums.size()<1)		//空数组的情况
		{
			return 0;
		}
		position = 1,mov_point=1;//指向第二个位置，第一个位置理所当然不需要被替换
		for ( ; mov_point < nums.size(); mov_point++)
		{
			if (nums[mov_point]!=nums[mov_point-1])		//出现不重复的数值
			{
				nums[position] = nums[mov_point];	//修改当前指向的位置的值
				position++;
				//由于mov_point在for循环里自加了，故这里一定不要自加
			}
		}
		return position;//position总是指向下一个位置，但不要忘记position[0]，故实际上是position-1+1
	}
};

int main(){}