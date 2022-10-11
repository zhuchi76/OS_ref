#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cmath>
#include <pthread.h>
#include <unistd.h>
# include <random>

using namespace std;

#define INTERVAL 10000

void *count(void *arg);
double arr[100000000];
int np, len;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long counts = 0;

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
	
    
    int interval;
    double rand_x, rand_y, pi;

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
  
        // Randomly generated x and y values
        rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
        rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;
  
        // Distance between (x, y) from the origin
        arr[i] = rand_x * rand_x + rand_y * rand_y;
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
	
    pi = double(4 * counts) / len;
    cout << "get: " << counts << "\n";
    cout << "Pi: " << pi << "\n";
	
	return 0;
}

void *count(void *arg)//int arr[], int begin, int end)
{
    pt *data = (pt *)arg;
    int begin = data->begin;
    int end = data->end;
	
    for(int i = begin; i < end; i++)
	{
        if (arr[i] <= 1)
        {
            //pthread_mutex_lock(&mutex);
            counts++;
            //pthread_mutex_unlock(&mutex);
        }
    }

    //pthread_exit(NULL);
    return NULL;
}