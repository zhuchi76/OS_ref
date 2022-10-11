#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cmath>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

void *c0(void *arg);
void *c1(void *arg);
void *c2(void *arg);
char arr[100000000];
int len;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static sem_t m10;
static sem_t m20;
static sem_t m1;
static sem_t m2;

long long counts[3] = {0};

struct pt{
    //int *arr;
    int begin, end;
};

int main(int argc, const char * argv[])
{
	pthread_t t0, t1, t2;
	pt d0, d1, d2;
	sem_init(&m10,0,0);
    sem_init(&m20,0,0);
	sem_init(&m1,0,0);
    sem_init(&m2,0,0);

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

	d0.begin = 0;
	d0.end = len/3;
	d1.begin = d0.end;
    d1.end = len/3*2;
    d2.begin = d1.end;
    d2.end = len;
    //cout << "d: " << d1.begin << ", " << d1.end << ", " << d2.end << ", " << d3.end << "\n";
    pthread_create(&t0, NULL, c0, (void*) &d0);
    pthread_create(&t1, NULL, c1, (void*) &d1);
    pthread_create(&t2, NULL, c2, (void*) &d2);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

	sem_destroy(&m10);
    sem_destroy(&m20);
	sem_destroy(&m1);
    sem_destroy(&m2);
	// for(int i = 0; i <= 2; i++)
	// {
	// 	cout << "m" << i << ": " << counts[i] << "\n";
	// }

	return 0;
}

void *c0(void *arg)//int arr[], int begin, int end)
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
	sem_wait(&m10);
	sem_wait(&m20);

	cout << "0: " << counts[0] << "\n";
	sem_post(&m1);
    //pthread_exit(NULL);
    return NULL;
}

void *c1(void *arg)//int arr[], int begin, int end)
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
	sem_post(&m10);
	//cout << "unlock10\n";
	
	sem_wait(&m1);
	cout << "1: " << counts[1] << "\n";
	sem_post(&m2);
    //pthread_exit(NULL);
    return NULL;
}

void *c2(void *arg)//int arr[], int begin, int end)
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
	sem_post(&m20);
	//cout << "unlock20\n";
	
	sem_wait(&m2);
	cout << "2: " << counts[2] << "\n";
    //pthread_exit(NULL);
    return NULL;
}
