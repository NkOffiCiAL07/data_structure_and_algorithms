#include<bits/stdc++.h>
using namespace std;

const int Size = 26;

struct node
{
	bool endofwords;
	node *ar[Size];
};

node *getNode()
{
	node *n = new node();
	n->endofwords = false;

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

		tempRoot = tempRoot->ar[idx];
	}

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

int main()
{
	node *root = getNode();

	int n;
	string st;
	while(1)
	{
		cin >> n;
		if(n == 1)
		{
			cout << "Enter string to insert\n";
			cin >> st;
			insert(root, st);
		}
		else if(n == 2)
		{
			cout << "Enter string to search\n";
			cin >> st;
			cout << search(root, st) << endl;
		}
		else break;
	}

	return 0;
}