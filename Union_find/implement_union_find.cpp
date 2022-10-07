#inlcude<bits/stdc++.h>
using namespace std;

struct dsu
{
	vector<int> mx, mn;
    vector<int> par, sz;
 	dsu(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
		mx.resize(n + 1);
		mn.resize(n + 1);
 		
        for(int i=1; i<=n; i++)
        {
            par[i] = i;
            sz[i] = 1;
            mn[i] = i;
            mx[i] = i;
        }
    }
 	
 	int minm(int a)
 	{
 		return mn[a];
 	}
 	
 	int maxm(int a)
 	{
 		return mx[a];
 	}
 		
 	
    int find(int x)
    {
        if(par[x] == x)
            return x;
            
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if(x == y) return;
        
        if(sz[x] > sz[y])
        {
            par[y] = x;
            sz[x] += sz[y];
            mn[x] = min(mn[x], mn[y]);
            mx[x] = max(mx[x], mx[y]);
        }
        else
        {
            par[x] = y;
            sz[y] += sz[x];
 			mn[y] = min(mn[x], mn[y]);
            mx[y] = max(mx[x], mx[y]);
        }
 
    }
 
    int size(int x)
    {   
        return sz[x];
    }
};

int main()
{

}