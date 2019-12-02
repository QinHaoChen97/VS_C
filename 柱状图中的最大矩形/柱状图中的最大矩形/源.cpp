/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
��������״ͼ��ʾ��������ÿ�����ӵĿ��Ϊ 1�������ĸ߶�Ϊ [2,1,5,6,2,3]��
���ܹ��ճ�������������������Ϊ 10 ����λ���м��5,6  5*2=10 ����
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//ʹ�õ���ջ
//���ĵ�˼�����Ե�ǰ��������Ϊ������̵����ӵ�ʱ������ε������Ϊ����
//�򵥾���
//[2,1,5,6]
//ջ�ı仯Ϊ
/*
                                  1<2���Խ�2��������������Ϊ��ǰ��̵����Ӽ���������
								  ������������ľ��뼴Ϊ��������ջ����һ��Ԫ�صľ��룬������Ϊ���εĵ�
								                                                                            �����󵯳�
												6															��ʱ�����㵱ǰ����Ϊ��̵ľ���Ϊheights.size()-stack.(top-1)-1;
										   5    5                                                           ע��heights.sizeΪ�����±�����ֵ+1 ,�䵱����ǰi��ֵ
			2         2            1       1    1
   -1       -1        -1		  -1      -1   -1                                                            
*/ 
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n==0)
		{
			return 0;
		}
		if (n==1)
		{
			return heights[0];
		}
		stack<int> sta;
		int maxsquare = 0;
		sta.push(-1);
		for (int i = 0; i < n; i++)
		{
			while(sta.top()!=-1 && heights[sta.top()]>heights[i])
			{
				int mini = heights[sta.top()];
				sta.pop();
				maxsquare = max(maxsquare, (i - sta.top() - 1)*mini);
			}
			sta.push(i);
		}
		while (sta.top()!=-1)
		{
			int mini = heights[sta.top()];
			sta.pop();
			maxsquare = max(maxsquare, (n - sta.top() - 1)*mini);
		}
		return maxsquare;
	}
};
int main()
{

}