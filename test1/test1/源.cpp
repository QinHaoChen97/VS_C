#include<iostream>
#include "��ͷ.h"
using namespace std;


void main()
{
	int A[5] = { 1,5,6,9,2 };
	testrange(A, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << A[i] << endl;
	}
}
