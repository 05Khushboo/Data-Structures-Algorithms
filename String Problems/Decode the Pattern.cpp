/*input
1
5
*/
// https://practice.geeksforgeeks.org/problems/decode-the-pattern/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
int main()
{
	string pattern[25];
	pattern[1] = "1";
	for(ll i = 2;i<=21;i++)
	{
		string nw;
		ll prechar = pattern[i-1][0];
		ll j = 1,cnt = 1;
		while(j<pattern[i-1].size())
		{
			if(prechar==pattern[i-1][j])
			{
				j++;
				cnt++;
			}
			else
			{
				nw+=to_string(cnt);
				nw+=prechar;
				prechar = pattern[i-1][j];
				j++;
				cnt = 1;
			}
		}
		nw+=to_string(cnt);
		nw+=prechar;
		pattern[i] = nw;
	}
	ll t; cin>>t;
	while(t--)
	{
		ll n; cin>>n;
		cout<<pattern[n]<<endl;
	}	
	return 0;
}