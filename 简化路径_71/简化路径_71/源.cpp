/*
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

 示例 1：

 输入："/home/"
 输出："/home"
 解释：注意，最后一个目录名后面没有斜杠。
 示例 2：

 输入："/../"
 输出："/"
 解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
 示例 3：

 输入："/home//foo/"
 输出："/home/foo"
 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
 示例 4：

 输入："/a/./b/../../c/"
 输出："/c"
 示例 5：

 输入："/a/../../b/../c//.//"
 输出："/c"
 示例 6：

 输入："/a//b////c/d//././/.."
 输出："/a/b/c"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/simplify-path
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;
//有一个坑 ... 是无意义的，把它看成一个目录
class Solution {
public:
	string simplifyPath(string path) {
		//为了满足下面的算法，手动为字符串末尾补'/'，这样可以使得末尾不会出现无用的'.'
		path = path + '/';
		int n = path.length();
		stack<char> sta;
		sta.push('/'); //先存放进一个根目录
		for (int i = 0; i < n; i++)
		{
			if (path[i]=='/')
			{
				if (sta.top() == '/')
				{
					continue;
				}
				else if(sta.top()=='.') // "./"表示当前目录
				{
					if (i>1 && path[i-2]=='.') //”../“
					{
						if (i>2 && path[i-3]=='.') //".../"
						{
							continue;
						}
						else //"../"
						{
							for (int j = 0; j < 2;)
							{
								while (sta.top() != '/')
								{
									sta.pop();
								}
								if (sta.size() == 1) //判断此时是否已经到根目录了，即path="/";
								{
									break;
								}
								else if (j == 0)
								{
									sta.pop();//将第一个‘/’弹出，第二'/'才说明是到了上一级
								}
								j++;
							}
						}
					}
					else //"./"
					{
						while (sta.top() != '/')
						{
							sta.pop();
						}
					}

				}
				else
				{
					sta.push(path[i]);
				}
			}
			else
			{
				sta.push(path[i]);
			}
		}
		//整个字符串处理完之后取出
		if (sta.size()==1) //说明只有根目录
		{
			return "/";
		}
		//对栈尾进行处理,栈尾有可能出现/
		string reckonpath = "";
		if (sta.top()=='/') //末尾如果是这种字符是无效的
		{
			sta.pop();
		}		
		while (!sta.empty())
		{
			reckonpath = sta.top()+reckonpath;
			sta.pop();  //处理stack的pop是void类型，要取值只能用top
		}
		return reckonpath;
	}
};

int main()
{
	string path = "/../";
	Solution a;
	a.simplifyPath(path);
	cin.get();
}