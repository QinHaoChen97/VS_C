#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
double AttackerSuccessProbalility(double q, int z)
{
	double p = 1.0 - q; //二项分布
	double lambda = z*1.0*(q / p); //特征参数
	double sum = 1.0;
	int i, k;
	for (k = 0; k<=z; k++)
	{
		double poisson = exp(-lambda);
		for ( i = 1; i <= k; i++)
		{
			poisson *= lambda / i;//实现lambda的k次方除以k的阶乘	
		}
		sum -= poisson*(1 - pow((q*1.0) / (p*1.0), z - k));
	}
	return sum;
}
int main() {
	vector<double> vec;
	for (double q = 0.1; q <=0.5; q+=0.2)
	{
		for (int z = 0; z < 11; z++)
		{
			vec.push_back(AttackerSuccessProbalility(q, z));
		}
		cout << "当攻击者的算力占全网"<<q<<"的追赶概率:" << endl;
		for (int i = 0; i < 11; i++)
		{
			cout <<"追赶的区块数为"<<i<<"追赶概率为:"<<vec[i] << endl;
		}
		vec.swap(vector<double>());
		
	}
	cin.get();
}