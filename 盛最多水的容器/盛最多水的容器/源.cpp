#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//˫ָ�뷨
//lָ�������󵲰壬rָ���������ҵ���
//˫ָ�뷨��ȷ�Ե�֤��https://leetcode-cn.com/problems/container-with-most-water/solution/shuang-zhi-zhen-fa-zheng-que-xing-zheng-ming-by-r3/
//�������area=��j-i)*min(i,j)
class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0, r = height.size() - 1;		//���ҵ��壬ע��size���ص��Ǹ��������±꣬Ҫ��ȥ1
		int maxarea=0;//���ڴ�����ʢˮ���
		int area = 0;//��ʱ������
		for (int i = 0; i < int(height.size() - 2); i++)		//������N�����ݣ���Ҫ�ƶ�N-2��,������ı�r������������r�����ƣ�ɵ�ƣ�
		{
			if (height[l] >= height[r])		//��Ҫ������������һ���ߵ����
			{
				area = (r - l)*height[r];	//�Խϵ͵ĵ���Ϊ��׼
				r--;//�ҵ��������ƶ�
			}
			else
			{
				area = (r - l)*height[l];
				l++;//�󵲰������ƶ�
			}
			if (area>maxarea)
			{
				maxarea = area;
			}
		}
		//���һ���ƶ��������û�м��㣬�����ﲹ�ϣ���ʱ���Ŀ�ȱض�Ϊ1��ֻ���������н϶̵ľ������
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