#include<bits/stdc++.h>
using namespace std;

int ar[1000];
int tree[4000];
void buildTree(int node, int start, int end)
{
	if(start == end)
		tree[node] = ar[start - 1];
	else
	{
		int mid = (start + end) / 2;
		buildTree(2 * node, start, mid);
		buildTree(2 * node + 1, mid + 1, end);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

void update(int node, int start, int end, int idx)
{
	if(start == end)
		tree[node] = ar[idx];
	else
	{
		int mid = (start + end) / 2;
		if(idx <= mid)
			update(2 * node, start, mid, idx);
		else
			update(2 * node + 1, mid + 1, end, idx);

		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(r < start || end < l)
		return INT_MAX;

	if(l <= start && end <= r)
		return tree[node];

	int mid = (start + end) / 2;
	int p1 = query(2 * node, start, mid, l, r);
	int p2 = query(2 * node + 1, mid + 1, end, l, r);

	return min(p1, p2);
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
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n+1, l+1, r+1) << "\n";
	}
	
	return 0;
}