/*input
5
1 6 2 1 9
*/
// https://www.hackerearth.com/problem/algorithm/close-subsequences-7fa6344b/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
int main()
{
	ll N = 5E5, mod = 1E9 + 7;
	ll n; cin>>n;
	ll tgood[N],tbad[N];
	for(ll i = 0;i<N;i++)
		tgood[i] = tbad[i] = 0;
	ll bad = 0, good = 0;
	while(n--)
	{
		ll x; cin>>x;
		ll pregood = tgood[x];
		ll prebad = tbad[x];
		tgood[x] = (tgood[x]+good+tbad[x-1]+tbad[x]+tbad[x+1])%mod;
		tbad[x] = (tbad[x]+1+bad-tbad[x-1]+mod-tbad[x]+mod-tbad[x+1]+mod)%mod;
		good = (good+tgood[x]-pregood+mod)%mod;
		bad = (bad+tbad[x]-prebad+mod)%mod; 
 	}
 	cout<<good;
	return 0;
}	