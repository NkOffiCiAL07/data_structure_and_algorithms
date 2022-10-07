#include<bits/stdc++.h>
using namespace std;

int ar[1000];
int tree[4000];

void buildTree(int node, int start, int end)
{
	if(start == end)
		tree[node] = ar[start-1];
	else
	{
		int mid = (start + end) / 2;
		buildTree(2 * node, start, mid);
		buildTree(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void update(int node, int start, int end, int idx, int val)
{
	if(start == end)
		tree[node] = val;
	else
	{
		int mid = (start + end) / 2;
		if(start <= idx && idx <= mid)
			update(2 * node, start, mid, idx, val);
		else
			update(2 * node + 1, mid + 1, end, idx, val);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

int sum(int node, int start, int end, int l, int r)
{
	if(r < start || end < l)
		return 0;

	if(l <= start && end <= r)
		return tree[node];

	int mid = (start + end) / 2;
	int p1 = sum(2 * node, start, mid, l, r);
	int p2 = sum(2 * node + 1, mid + 1, end, l, r);

	return p1 + p2;
}

int main()
{
	int n; cin >> n;
	for(int i=0; i<n; i++)
		cin >> ar[i];

	buildTree(1, 1, n+1);
	int q; cin >> q;
	while(q--)
	{
		int x; cin >> x;
		if(x == 1)
		{
			int idx, val;
			cin >> idx >> val;
			update(1, 1, n+1, idx, val);
		}
		else 
		{
			int l, r;
			cin >> l >> r;
			cout << "sum : " << sum(1, 1, n+1, l, r) << "\n";
		}
	}
	
	return 0;
}