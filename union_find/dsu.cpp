#include<bits/stdc++.h>
using namespace std;

struct dsu
{
    vector<int> par, sz;
    dsu(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
 
        for(int i=1; i<=n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
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

        if(x == y) 
            return;

        if(sz[x] > sz[y])
        {
            par[y]=x;
            sz[x]+=sz[y];
        }
        else
        {
            par[x] = y;
            sz[y] += sz[x];
        }
 
    }
 
    int size(int x)
    {   
        x = find(x);
        return sz[x];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    dsu d(n);
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        if(d.find(x+1) != d.find(y+1))
            d.unite(x+1, y+1);
    }

    set<int> s;
    for(int i=1; i<=n; i++)
    {
        s.insert(d.find(i));
    }

    cout << s.size() << endl;

    return 0;
}