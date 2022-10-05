#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if(s1 == s2)
	{
		cout << "S1 = S2\n";
	}
	else if(s1 < s2)
	{
		cout << "S1 < S2\n";
	}
	else
		cout << "S1 > S2\n";

	return 0;
}