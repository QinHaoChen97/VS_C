//�жϻ�����
#include<iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		//���ж��Ƿ�С��0���ǵĻ�һ�����ǻ�����
		if (x<0)
		{
			return false;
		}
		//��������תһ�����ǻ�����
		int inverse = 0;
		int origin = x;
		while (x!=0)
		{
			int rem = x % 10; //ȡ����
			x /= 10;
			//�ж��Ƿ�Խ��,��������ǻ�������ز���Խ��
			if (inverse>INT_MAX/10 || inverse==INT_MAX/10&&rem>7)
			{
				return false;
			}
			else
			{
				inverse = inverse * 10 + rem;
			}
		}
		if (inverse==origin)
		{
			return true;
		}
		return false;
	}
};

//һ�ָ�����ķ�����ֻ��תһ��
class SolutionA {
public:
	bool isPalindrome(int x) {
		//���ж��Ƿ�С��0���ǵĻ�һ�����ǻ�����
		if (x<0 || (x % 10 == 0 && x != 0))//��Ϊ���һ�����Ľ�β��0����ô��һ�����ǻ�����,�����������Ϊ0
		{
			return false;
		}
		//��������תһ�����ǻ�����
		int inverse = 0;
		while (1)
		{
			int rem = x % 10; //ȡ����
			x /= 10;
			//�ж��Ƿ�Խ��,��������ǻ�������ز���Խ��
			//��Ϊֻ��תһ�룬�ʲ�����Ҫ�ж�Խ��
			/*if (inverse>INT_MAX / 10 || inverse == INT_MAX / 10 && rem>7)
			{
			return false;
			}
			else
			{
			inverse = inverse * 10 + rem;
			}*/
			inverse = inverse * 10 + rem;
			//���ǽ�ԭʼ���ֳ��� 10��Ȼ�����ת������ֳ��� 10�����ԣ���ԭʼ����С�ڷ�ת�������ʱ������ζ�������Ѿ�������һ��λ�������֡�
			if (inverse == x)//ż����������ɵĻ�������������Ϊ������
			{
				return true;
			}
			if (inverse>x)
			{
				//�ж��Ƿ���������������ֵ����
				if (inverse / 10 == x) //��Ϊinverse�Ƿ�ת�ģ���10�൱��ȥ���м�һλ
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
};
int main()
{
	int x = 121;
	Solution a;
	a.isPalindrome(x);
	cin.get();
}