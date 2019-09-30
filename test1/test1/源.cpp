#include<iostream>
using namespace std;
void range(int A[], int n);

void main()
{
	int A[5] = { 1,5,6,9,2 };
	range(A, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << A[i] << endl;
	}
}

void range(int A[], int n)
{
	bool rangbool = false;
	while (!rangbool)
	{
		rangbool = true;
		for (int i = 0; i < n; i++)
		{
			if (A[i - 1]>A[i])
			{
				swap(A[i - 1], A[i]);
				rangbool = false;
			}
		}
		n--;
	}
}