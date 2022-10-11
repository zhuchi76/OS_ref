#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct pr{
	int id;
	int rb;
};

int main()
{
    int n, qt, ar[99999],bu[99999], i, wt[99999] = {0}, twt, ttt;
    
    queue<pr> qu;
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
	ind = 1;
	t = ar[0];
	p.id = 0;
	p.rb = bu[0];
	qu.push(p);
	
	while (1)
    {
        bool ch = true;
	
		//cout << "ch1\n";
		
		//cout << "ch2\n";
		//push in queue
//        if(!ch)
//        {
//        	for(ind; ind < i; ind++)
//        	{
//        		p.id = ind;
//                p.rb = bu[ind];
//                qu.push(p);
//                cout << "p in queue\n";
//                cout << "id: " << p.id << "\n";
//                cout << "bu: " << p.rb << "\n";
//                cout << "\n";
//			}
//			ind = i+1;
//        	continue;
//		}
//        for(ind; ind < n; ind++)
//        {
//        	if(t >= ar[ind])
//        	{
//        		p.id = ind;
//            	p.rb = bu[ind];
//            	qu.push(p);
//			}
//        	else
//        	{
//        		break;
//			}
//		}
        
        //cout << "ch3\n";
		//run queue
        if (!qu.empty())
        {
            ch = false;
			
			p = qu.front();
			qu.pop();
            if(p.rb > qt)
            {
                t += qt;
                p.rb -= qt;
                // cout << "time1: " << t << "\n";
                // cout << "id: " << p.id << "\n";
                // cout << "bu: " << p.rb << "\n";
                // cout << "\n";
                for(ind; ind < n; ind++)
		        {
		        	if(t >= ar[ind])
		        	{
		        		pr p2;
		        		p2.id = ind;
		            	p2.rb = bu[ind];
		            	qu.push(p2);
		            	// cout << "p push queue1\n";
		                // cout << "id: " << p2.id << "\n";
		                // cout << "bu: " << p2.rb << "\n";
		                // cout << "\n";
					}
		        	else
		        	{
		        		break;
					}
				}
                qu.push(p);
            }
            else
            {
                t += p.rb;
                // cout << "time2: " << t << "\n";
                // cout << "id: " << p.id << "\n";
                // cout << "bu: " << p.rb << "\n";
                // cout << "\n";
                wt[p.id] = t - ar[p.id] - bu[p.id];
                for(ind; ind < n; ind++)
		        {
		        	if(t >= ar[ind])
		        	{
		        		pr p2;
		        		p2.id = ind;
		            	p2.rb = bu[ind];
		            	qu.push(p2);
		            	// cout << "p push queue2\n";
		                // cout << "id: " << p2.id << "\n";
		                // cout << "bu: " << p2.rb << "\n";
		                // cout << "\n";
					}
		        	else
		        	{
		        		break;
					}
				}
            }
        }
        else if(ind < n)
        {
        	ch = false;
        	t = ar[ind];
        	p.id = ind;
        	p.rb = bu[ind];
        	qu.push(p);
        	ind++;
        	// cout << "empty time: " << t << "\n";
        	// cout << "id: " << p.id << "\n";
		    // cout << "bu: " << p.rb << "\n";
		    // cout << "\n";
		}

        if (ch == true)
        {
        	break;
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
