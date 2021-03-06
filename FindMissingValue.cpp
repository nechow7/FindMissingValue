// nc2148_hwkk7_q7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
const int length = 6;

int* findMissing(int arr[], int n, int& resArrSize);

int main()
{
	int arr[6],num;
	cout << "Please enter 6 numbers into the array less than 6: \n";
	for (size_t i = 0; i < 6; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	int* arr2;
	int count,i;
	count = 0;

	arr2 = findMissing(arr, length, count);

	for (i = 0; i < count; i++)
	{
		cout << arr2[i] << ' ';
	}

	return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
	int *holder = new int[n];
	int i,count;
	count = n;

	// creates an array with values 0 to n
	for ( i = 0; i < n; i++)
	{
		holder[i] = i;
	}
	// looks through arr to see what values there, and puts a -1 in holder 
	for ( i = 0; i < n; i++)
	{
		if ((arr[i] < n)&&(holder[arr[i]] != -1))
		{
			holder[arr[i]] = -1;
			count -= 1;
		}
	}
	
	int* newArr = new int[count];
	int holder2 = 0;
	// for the values in holder that are not equal to -1, they are put in new holder array which will be returned
	for ( i = 0; i < n; i++)
	{
		if (holder[i] != -1)
		{
			newArr[holder2] = holder[i];
			holder2 += 1;
		}

	}

	resArrSize = count;

	return newArr;
}

