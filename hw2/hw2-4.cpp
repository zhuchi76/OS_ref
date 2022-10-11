#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

struct pr{
	int id;
	int rb;
};

int main()
{
    int n, qt, ar[99999],bu[99999], i, wt[99999] = {0}, twt, ttt;
    
	queue<pr> qu1;
    vector<pr> qu2;
    pr p;
    
    cin>>n;
    for(i = 0; i < n; i++)
    {
    	cin >> ar[i];
	}
	for(i = 0; i < n; i++)
    {
    	cin >> bu[i];
	}
	cin >> qt;

	int t, ind;
	ind = 0;
	t = ar[0];
	
	//cout << "ch\n";
	while (ind < n || !qu1.empty() || !qu2.empty())
    {
		//cout << "ch2\n";
		for(ind; ind < n; ind++)
		{
			//cout <<"ch3\n";
			if(t >= ar[ind])
			{
				p.id = ind;
				p.rb = bu[ind];
				qu1.push(p);
				// cout << "p push queue1\n";
				// cout << "id: " << p.id << "\n";
				// cout << "bu: " << p.rb << "\n";
				// cout << "\n";
			}
			else
			{
				//cout <<"ch4\n";
				break;
			}
		}

        if (!qu1.empty())//run robin
        {
			p = qu1.front();
			qu1.pop();
            if(p.rb > qt)
            {
                t += qt;
                p.rb -= qt;
                // cout << "time1: " << t << "\n";
                // cout << "id: " << p.id << "\n";
                // cout << "bu: " << p.rb << "\n";
                // cout << "\n";
				if(qu2.empty())
				{
					qu2.push_back(p);
					// cout << "p push queue2\n";
					// cout << "id: " << p.id << "\n";
					// cout << "bu: " << p.rb << "\n";
					// cout << "\n";
				}
                else
				{
					for(i = 0; i < qu2.size(); i++)
					{
						if(p.rb >= qu2[i].rb)
						{
							qu2.insert(qu2.begin() + i, p);
							// cout << "p push queue2-2\n";
							// cout << "id: " << p.id << "\n";
							// cout << "bu: " << p.rb << "\n";
							// cout << "\n";
							break;
						}
					}
					if(i == qu2.size())
					{
						qu2.push_back(p);
						// cout << "p push queue2-3\n";
						// cout << "id: " << p.id << "\n";
						// cout << "bu: " << p.rb << "\n";
						// cout << "\n";
					}
				}
			}
            else
            {
                t += p.rb;
                // cout << "time2: " << t << "\n";
                // cout << "id: " << p.id << "\n";
                // cout << "bu: " << p.rb << "\n";
                // cout << "\n";
                wt[p.id] = t - ar[p.id] - bu[p.id];
			}
		}
		else if(!qu2.empty())
		{
			int rt;
			if(ind < n)
			{
				rt = ar[ind] - t;
			}
			else
			{
				while(!qu2.empty())
				{
					p = qu2[qu2.size() - 1];
					qu2.pop_back();
					t += p.rb;
					wt[p.id] = t - ar[p.id] - bu[p.id];
					// cout << "end: " << t << "\n";
					// cout << "id: " << p.id << "\n";
					// cout << "bu: " << p.rb << "\n";
					// cout << "\n";
				}
				rt = 0;
			}
			// cout << "q2empty: " << t << "\n";
			// cout << "id: " << ind << "\n";
			// cout << "arind: " << ar[ind] << "\n";
			// cout << "\n";

			while(rt)
			{
				p = qu2[qu2.size() - 1];
				qu2.pop_back();
				if(p.rb < rt)
				{
					t += p.rb;
					rt -= p.rb;
					wt[p.id] = t - ar[p.id] - bu[p.id];
					// cout << "time3: " << t << "\n";
					// cout << "id: " << p.id << "\n";
					// cout << "bu: " << p.rb << "\n";
					// cout << "\n";
				}
				else
				{
					t += rt;
					p.rb -= rt;
					rt = 0;
					qu2.push_back(p);
					rt = 0;
					// cout << "time4: " << t << "\n";
					// cout << "id: " << p.id << "\n";
					// cout << "bu: " << p.rb << "\n";
					// cout << "\n";
				}
			}
			//t = ar[ind];
		}

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
