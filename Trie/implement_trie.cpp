#include<bits/stdc++.h>
using namespace std;

const int Size = 26;
struct node
{
	bool endofwords;
	bool startwith;
	node *ar[Size];
};

node *getNode()
{
	node *n = new node();
	n->endofwords = false;
	n->startwith = false;

	for(int i=0; i<Size; i++)
		n->ar[i] = NULL;

	return n;
}

void insert(node *root, string s)
{
	node *tempRoot = root;
	for(int i=0; i<s.size(); i++)
	{
		int idx = s[i] - 'a';

		if(tempRoot->ar[idx] == NULL)
			tempRoot->ar[idx] = getNode();

		tempRoot->startwith = true;
		tempRoot = tempRoot->ar[idx];
	}

	tempRoot->startwith = true;
	tempRoot->endofwords = true;
}

bool search(node *root, string s)
{
	node *tempRoot = root;
	for(int i=0; i<s.size(); i++)
	{
		int idx = s[i] - 'a';

		if(tempRoot->ar[idx] == NULL)
			return false;

		tempRoot = tempRoot->ar[idx];
	}

	return tempRoot->endofwords;	
}

bool startWith(node *root, string s)
{
	node *tempRoot = root;
	for(int i=0; i<s.size(); i++)
	{
		int idx = s[i] - 'a';

		if(tempRoot->ar[idx] == NULL)
			return false;

		tempRoot = tempRoot->ar[idx];
	}

	return tempRoot->startwith;		
}

int main()
{
	node *root = getNode();

	int n; cin >> n;
	string s;
	char ch;
	for(int i=0; i<n; i++)
	{
		cin >> ch;
		if(ch == 'i')
		{
			cin >> s;
			insert(root, s);
		}

		if(ch == 's')
		{
			cin >> s;
			if(search(root, s))
				cout << "YES ";
			else
				cout << "NO ";
		}

		if(ch == 'w')
		{
			cin >> s;
			if(startWith(root, s))
				cout << "YES ";
			else
				cout << "NO ";
		}
	}
}	
