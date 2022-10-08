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
            par[y] = x;
            sz[x] += sz[y];
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
    int t; cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        dsu d(n);
        vector<pair<int, int>> p;
        for(int i=0; i<m; i++)
        {
            int x, y;
            cin >> x >> y;
            p.push_back({x, y});
        }

        bool flag = 0;
        for(int i=0; i<m; i++)
        {
            int x = p[i].first + 1;
            int y = p[i].second + 1;
            
            cout << x << " " << y << endl;
            cout << d.find(x) << " " << d.find(y) << endl;
            cout << endl;
            if(d.find(x) == d.find(y))
            {
                cout << "NO\n";
                flag = 1;
                break;
            }
            
            d.unite(x, y);
        }       

        if(!flag)
            cout << "YES\n";
    }

    return 0;
}