#include<iostream>
#include<vector>
using namespace std;
//格雷码，编程最简单，但是要知道公式
//格雷编码公式 G(i) = i ^ (i / 2);
//如 n = 3:
//G(0) = 000,
//G(1) = 1 ^ 0 = 001 ^ 000 = 001
//G(2) = 2 ^ 1 = 010 ^ 001 = 011
//G(3) = 3 ^ 1 = 011 ^ 001 = 010
//G(4) = 4 ^ 2 = 100 ^ 010 = 110
//G(5) = 5 ^ 2 = 101 ^ 010 = 111
//G(6) = 6 ^ 3 = 110 ^ 011 = 101
//G(7) = 7 ^ 3 = 111 ^ 011 = 100
//————————————————
//版权声明：本文为CSDN博主「Zolewit」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/zolewit/article/details/90715308
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> gray;
		for (int i = 0; i < (1<<n); i++)	//C++存储的时候实际是2进制，故左移实际上是乘2，1<<n=1*2的n次方，n位格雷码共有2^n-1个码元
		{
			gray.push_back(i ^ (i / 2));	//根据格雷码的公式，注意^是c++中的异或
		}
		return gray;
	}
};
int main()
{
	int a = 0b1111;
}