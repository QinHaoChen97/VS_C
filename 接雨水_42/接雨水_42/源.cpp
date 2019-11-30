//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

/*
我们用栈保存每堵墙。

当遍历墙的高度的时候，如果当前高度小于栈顶的墙高度，说明这里会有积水，我们将墙的高度的下标入栈。

如果当前高度大于栈顶的墙的高度，说明之前的积水到这里停下，我们可以计算下有多少积水了。计算完，就把当前的墙继续入栈，作为新的积水的墙。

总体的原则就是，

当前高度小于等于栈顶高度，入栈，指针后移。

当前高度大于栈顶高度，出栈，计算出当前墙和栈顶的墙之间水的多少，然后计算当前的高度和新栈的高度的关系，重复第 2 步。直到当前墙的高度不大于栈顶高度或者栈空，然后把当前墙入栈，指针后移。

作者：windliang
链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
//题解参考https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
//使用栈的方法求解
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> wall;
		int current = 0; //用于存储当前指向的位置，进栈的时候也存入该值，方便计算两墙之间的距离
		int sum = 0;//存放雨水
		while (current<height.size())
		{
			while (!wall.empty() && height[current]>height[wall.top()]) //数组非空且当前指向的挡板高度大于栈顶挡板高度，由于前提是数组非空，所以不用担心访问越界
				//当这种情况出现时，1 有可能是两挡板中出现了一矮挡板，2 也有可能是只有一边高挡板的情况
			{
				int tp = height[wall.top()];
				wall.pop(); //将栈顶出栈
				if (wall.empty())//排除上面的情况二
				{
					break;
				}
				int distance = current - wall.top()-1; //得到两挡板之间的距离
				sum += (min(height[wall.top()], height[current]) - tp)*distance;//两墙中较低的墙减去两挡板中较矮的地方*两挡板间的距离

			}
			wall.push(current++);//即push（current）;current+1;  因为current++返回的是未自加前的结果
		}
		return sum;

	}
};
int main()
{

}