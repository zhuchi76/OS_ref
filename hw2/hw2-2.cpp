#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

struct pr{
	int id;
	int b;
};

int main()
{
    int n, ar[99999],bu[99999], i, wt[99999] = {0}, twt, ttt;
    
    vector<pr> qu;
    pr p;
    p.id=-1;
    p.b=INT_MAX;
    qu.push_back(p);
    
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
	

	int time, ind, ch;
	wt[0] = 0;
	time = ar[0]+bu[0];
	ch = 1;
	//size = 0;
	for(i = 1; i < n; i++)
	{
		if(time < ar[i] && qu.size() == 1)
		{
			time = ar[i];		
		}
		//cout << "1qu.size(): " << qu.size() << "\n";
		while(ar[ch] < time && ch < n)
		{
			//cout << "ch: " << ch << "\n";
			p.id = ch;
			p.b = bu[ch];
			//cout << "p.id: " << p.id << "\n";
			//cout << "p.b: " << p.b << "\n";
			int x;
			for(x = 1; x < qu.size(); x++)
			{
				if(p.b >= qu[x].b)
				{
					qu.insert(qu.begin() + x, p);
					//size++;
					break;
				}
			}
			//cout << "x: " << x << "\n";
			if(x == qu.size())
			{
				qu.push_back(p);
			}
			ch++;
		}
		//cout << "qu.size(): " << qu.size() << "\n";
		ind = qu[qu.size()-1].id;
		//cout << "id: " << ind << "\n";
		//cout << "time1: " << time << "\n";
		wt[ind] = time-ar[ind];
		time += bu[ind];
		//cout << "qu[ind].b: " << qu[ind].b << "\n";
		qu.pop_back();
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
