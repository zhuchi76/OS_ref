#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cmath>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void *count(void *arg);
char arr[100000000];
int np, len;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long counts[3] = {0};

struct pt{
    //int *arr;
    int begin, end;
};

int main(int argc, const char * argv[])
{
	pthread_t t1, t2, t3, t4;
	pt d1, d2, d3, d4;
	cin >> np;
	cin >> len;
	//cin.ignore();
	for(int i = 0; i < len; i++)
	{
		cin >> arr[i];// = cin.get() - '0';
	}
//	for(int i = 0; i < len; i++)
//	{
//		cout << arr[i];
//	}
	
	if(np == 1)
	{
	    d1.begin = 0;
	    d1.end = len;
	    pthread_create(&t1, NULL, count, (void*) &d1);
	    pthread_join(t1, NULL);
	}
	else if(np == 2)
	{
		d1.begin = 0;
		d1.end = len/2;
		d2.begin = d1.end;
	    d2.end = len;
	    //cout << "d: " << d1.begin << ", " << d1.end << ", " << d2.end << "\n";
	    //pthread_mutex_lock(&mutex);
	    pthread_create(&t1, NULL, count, (void*) &d1);
	    //pthread_join(t1, NULL);
	    //pthread_mutex_unlock(&mutex);
	    
	    //pthread_mutex_lock(&mutex);
	    pthread_create(&t2, NULL, count, (void*) &d2);
	    pthread_join(t1, NULL);
	    pthread_join(t2, NULL);
		//pthread_mutex_unlock(&mutex);
	}
	else if(np == 3)
	{
		d1.begin = 0;
		d1.end = len/3;
		d2.begin = d1.end;
	    d2.end = len/3*2;
	    d3.begin = d2.end;
	    d3.end = len;
	    //cout << "d: " << d1.begin << ", " << d1.end << ", " << d2.end << ", " << d3.end << "\n";
	    pthread_create(&t1, NULL, count, (void*) &d1);
	    pthread_create(&t2, NULL, count, (void*) &d2);
	    pthread_create(&t3, NULL, count, (void*) &d3);
	    pthread_join(t1, NULL);
	    pthread_join(t2, NULL);
	    pthread_join(t3, NULL);
	}
	else // np == 4
	{
		d1.begin = 0;
		d1.end = len/4;
		d2.begin = d1.end;
	    d2.end = len/4*2;
	    d3.begin = d2.end;
	    d3.end = len/4*3;
	    d4.begin = d3.end;
	    d4.end = len;
	    //cout << "d: " << d1.begin << ", " << d1.end << ", " << d2.end << ", " << d3.end << "\n";
	    pthread_create(&t1, NULL, count, (void*) &d1);
	    pthread_create(&t2, NULL, count, (void*) &d2);
	    pthread_create(&t3, NULL, count, (void*) &d3);
	    pthread_create(&t4, NULL, count, (void*) &d4);
	    pthread_join(t1, NULL);
	    pthread_join(t2, NULL);
	    pthread_join(t3, NULL);
	    pthread_join(t4, NULL);
	}
	
	for(int i = 0; i <= 2; i++)
	{
		cout << i << ": " << counts[i] << "\n";
	}
	
	return 0;
}

void *count(void *arg)//int arr[], int begin, int end)
{
    pt *data = (pt *)arg;
    int begin = data->begin;
    int end = data->end;
	
    for(int i = begin; i < end; i++)
	{
	    pthread_mutex_lock(&mutex);
		counts[arr[i] - '0'] += 1;
		//cout << "p" << arr[i] << ": " << counts[arr[i] - '0'] << "\n";
		pthread_mutex_unlock(&mutex);
    }

    //pthread_exit(NULL);
    return NULL;
}
