#pragma once
#include<iostream>
using namespace std;

void testrange(int A[], int n);
void testrange(int A[], int n)
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