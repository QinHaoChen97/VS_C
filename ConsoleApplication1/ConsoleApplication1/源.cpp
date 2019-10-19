#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
int main()
{
	int n,max,segmax;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bool allnegative=true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			allnegative = false;
			break;
		}
	}

	if (allnegative)
	{
		max = a[0];
		for (int i = 0; i < n; i++)
		{
			if (max<a[i])
			{
				max = a[i];
			}
		}
		cout << max << endl;
		delete[]a;
		return 0;
	}
	else
	{
		segmax = 0;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			segmax = segmax + a[i];
			if (max <= segmax)
			{
				max = segmax;
			}
			if (segmax<0)
			{
				segmax = 0;
			}
		}
		cout << max << endl;
		delete[]a;
		return 0;
	}
	
}