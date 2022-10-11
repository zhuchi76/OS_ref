#include<iostream>
#include <iomanip>

using namespace std;
 
int main()
{
    int n,ar[99999],bu[99999], i, wt[99999] = {0}, twt, ttt;
    cin>>n;
 
    for(i = 0; i < n; i++)
    {
    	cin >> ar[i];
    	wt[i] = 0;
	}
	for(i = 0; i < n; i++)
    {
    	cin >> bu[i]; 
	}
	
	i = 1;
	int time = ar[0];
	wt[0] = 0;
	while(i < n)
	{
		time += bu[i-1];
		if(time > ar[i])
		{
			wt[i] += time - ar[i];
		}
		else
		{
			time = ar[i];
		}
		i++;
	}
	
	twt = 0;
	ttt = 0;
	//cout << "Process  Waiting Time    Turnaround Time\n"; 
	for(i = 0; i < n; i++)
    {
    	//cout << "P[" << i+1 << "]     ";
    	//cout << setiosflags(ios::left) << setw(16) << wt[i];
		//cout << setiosflags(ios::left) << setw(16) << wt[i]+bu[i] << "\n";;
		cout << wt[i] << " " << wt[i]+bu[i] << "\n";
		twt += wt[i];
		ttt += bu[i];
	}
	ttt += twt;
	//cout << "Total waiting time: " << twt << "\n";
	//cout << "Total turnaround time: " << ttt << "\n";
	cout << twt << "\n" << ttt << "\n";
 
    return 0;
}
