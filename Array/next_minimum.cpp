#include<bits/stdc++.h>
using namespace std;

//
vector<int> next_minimum(vector<int> &ar)
{
	vector<int> p;
	int n = ar.size();
	stack<int> s;
	for(int i=n-1; i>=0; i--)
	{
		if(s.empty())
			p.push_back(-1);
		else
		{
			while(!s.empty() && ar[s.top()] >= ar[i])
				s.pop();
		    
		    if(s.empty())
                p.push_back(-1);
            else
                p.push_back(s.top());
        }
            
        s.push(i);
	}

	reverse(p.begin(), p.end());
	return p;
}

int main()
{
	int n; cin >> n;
	vector<int> ar(n);
	for(int i=0; i<n; i++)
		cin >> ar[i];

	vector<int> ans = next_minimum(ar);
	for(int i=0; i<n; i++)
		cout << ans[i] << " ";

	return 0;
}