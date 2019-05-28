/*input
5 3
1 3 0 2 1
1 3
2 4
1 4
*/
// https://codeforces.com/contest/1169/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
int main()
{
	ll n, q; cin >> n >> q;

	ll arr[n], dp[n+1][32], last[32];
	for(ll i = 0; i < n; i++) cin >> arr[i];

	for(ll i = 0; i <= n; i++)
		for(ll j = 0; j <= 31; j++)
			dp[i][j] = n, last[j] = n;

	for(ll i = n - 1; i >= 0; i--)
	{
		for(ll j = 0; j <= 31; j++)
		{
			if(arr[i] & (1 << j))
			{
				for(ll k = 0; k <= 31; k++)
					dp[i][k] = min(dp[i][k], dp[last[j]][k]);

				dp[i][j] = last[j] = i;
			}
		}
	}

	while(q--)
	{
		ll x, y; cin >> x >> y;
		x--; y--;
		ll flag = 0;
		for(ll j = 0; j <= 31; j++)
			if(arr[y] & (1 << j))
				flag += dp[x][j] <= y ? 1 : 0;

		if(flag) cout << "Shi" << endl;
		else cout << "Fou" << endl;
	}
	return 0;
}