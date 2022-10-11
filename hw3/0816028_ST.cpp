#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cmath>

using namespace std;

#define N 2 // must be 2^x
int cut_m = log(N) / log(2);

void bubble_sort(int arr[], int begin, int end);
void merge(int arr[], int begin, int mid, int end);
void merge_sort(int arr[], int begin, int end, int cut);

int main(int argc, const char * argv[])
{
	int a[1000000];
	int i;
	int max = 0;
	// cin >> i;
	while(cin >> i)//i!=0)//cin >> i)
	{
//		cout << "i: " << i << "\n";
		a[max] = i;
		max++;
		// cin >> i;
	}
	
	// int chunk_size = max / N
	// int bonus = array_size - chunk_size * N  // i.e. remainder

	// for (begin = 0, end = chunk_size; begin < array_size; begin = end, end = begin + chunk_size)
	// {
	// 	if(bonus) 
	// 	{
	// 		end++;
	// 		bonus--;
	// 	}
	// 	bubble_sort(arr, begin, end);
	// }
	merge_sort(a, 0, max-1, 0);
	
	for(int i = 0; i < max; i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}

void bubble_sort(int arr[], int begin, int end)
{
    for(int i = end; i > begin; i--)
	{
        for(int j = begin; j < i; j++)
		{
            if(arr[j] > arr[j+1])
			{
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void merge(int arr[], int begin, int mid, int end)
{
	int lm = mid-begin+1;
	int rm = end-mid;
    int left[lm+1];
    int right[rm+1];
	
    for(int i = begin, li = 0; i <= mid; i++, li++)
    {
    	left[li] = arr[i];
	}
	left[lm] = INT_MAX;
	for(int i = mid+1, ri = 0; i <= end; i++, ri++)
    {
    	right[ri] = arr[i];
	}
	right[rm] = INT_MAX;
//	cout << "l[" << begin << "][" << mid << "]\n";
//	for(int i = 0; i <= lm; i++)
//	{
//		cout << left[i] << " ";
//	}
//	cout << "\n";
//	cout << "r[" << mid+1 << "][" << end << "]\n";
//	for(int i = 0; i <= rm; i++)
//	{
//		cout << right[i] << " ";
//	}
//	cout << "\n";
	

    int li = 0, ri = 0;
    for (int i = begin; i <= end; i++) {
        if (left[li] <= right[ri] ) {
            arr[i] = left[li];
            //cout << "l[" << i << "]: " << arr[i] << "\n";
            li++;
        }
        else{
            arr[i] = right[ri];
            //cout << "r[" << i << "]: " << arr[i] << "\n";
            ri++;
        }
    }
    
//	cout << "merge[" << begin << "][" << end << "]\n";
//	for(int i = begin; i <= end; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
}

void merge_sort(int arr[], int begin, int end, int cut)
{
    if (cut >= cut_m)
    {
    	bubble_sort(arr, begin, end);
    	// cout << "bubble[" << begin << "][" << end << "]\n";
    	// for(int i = begin; i <= end; i++)
    	// {
    	// 	cout << arr[i] << " ";
		// }
		// cout << "\n";
    	return;
	}

    int mid = (begin + end) / 2;
    merge_sort(arr, begin, mid, cut+1);
    merge_sort(arr, mid + 1, end, cut+1);
    merge(arr, begin, mid, end);
}
