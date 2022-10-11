#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cmath>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define N 8 // must be 2^x
int cut_m = log(N) / log(2);

void *bubble_sort(void *arg);
void *merge(void *arg);
void merge_sort(int begin, int end, int cut);
int a[1000000];

struct pt{
    int *arr;
    int begin, mid, end;
};

int main(int argc, const char * argv[])
{
//	int a[1000000];//
	int i;
	int max = 0;
//	cin >> i;
	while(cin >> i)
	{
//		cout << "i: " << i << "\n";
		a[max] = i;
		max++;
		//cin >> i;
	}
	
	merge_sort(0, max-1, 0);
	
	for(int i = 0; i < max; i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}

void *bubble_sort(void *arg)//int arr[], int begin, int end)
{
    pt *data = (pt *)arg;
//    int *arr = data->arr;
    int begin = data->begin;
    int end = data->end;

//    for(int i = end; i > begin; i--)
//	{
//        for(int j = begin; j < i; j++)
//		{
//            if(arr[j] > arr[j+1])
//			{
//                int temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//        }
//    }
//
//    data->arr = arr;
    for(int i = end; i > begin; i--)
	{
        for(int j = begin; j < i; j++)
		{
            if(a[j] > a[j+1])
			{
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    data->arr = a;
    pthread_exit(NULL);
}

void *merge(void *arg)//int arr[], int begin, int mid, int end)
{
    pt *data = (pt *)arg;
//    int *arr = data->arr;
    int begin = data->begin;
    int mid = data->mid;
    int end = data->end;

	int lm = mid-begin+1;
	int rm = end-mid;
    int left[lm+1];
    int right[rm+1];
	
    for(int i = begin, li = 0; i <= mid; i++, li++)
    {
//    	left[li] = arr[i];//
		left[li] = a[i];
	}
	left[lm] = INT_MAX;
	for(int i = mid+1, ri = 0; i <= end; i++, ri++)
    {
//    	right[ri] = arr[i];//
		right[ri] = a[i];
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
            a[i] = left[li];
            //cout << "l[" << i << "]: " << arr[i] << "\n";
            li++;
        }
        else{
            a[i] = right[ri];
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

//    data->arr = arr;//
	data->arr = a;
    pthread_exit(NULL);
}

void merge_sort(int begin, int end, int cut)
{
    if (cut >= cut_m)
    {
        pthread_t t;
        pt data;
//        data.arr = arr;
        data.begin = begin;
        data.end = end;
        pthread_create(&t, NULL, bubble_sort, (void*) &data);
        pthread_join(t, NULL);
        for(int i = begin; i <= end; i++)
    	{
    		a[i] = data.arr[i];
		}
    	//bubble_sort(arr, begin, end);
    	// cout << "bubble[" << begin << "][" << end << "]\n";
    	// for(int i = begin; i <= end; i++)
    	// {
    	// 	cout << arr[i] << " ";
		// }
		// cout << "\n";
    	return;
	}

    int mid = (begin + end) / 2;
    merge_sort(begin, mid, cut+1);
    merge_sort(mid + 1, end, cut+1);

    pthread_t t;
    pt data;
//    data.arr = arr;//
    data.begin = begin;
    data.mid = mid;
    data.end = end;
    pthread_create(&t, NULL, merge, (void*) &data);
    pthread_join(t, NULL);
    for(int i = begin; i <= end; i++)
    {
//        arr[i] = data.arr[i];//
        a[i] = data.arr[i];
    }
    //merge(arr, begin, mid, end);
}
