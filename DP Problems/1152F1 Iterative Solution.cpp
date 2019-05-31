/*input
3 3 1
*/
// https://codeforces.com/contest/1152/problem/F1
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
ll Ones(ll mask)
{
	ll cnt = 0;
	while(mask > 0)
	{
		if(mask & 1)
			cnt++;
		mask >>= 1; 
	}

	cnt += 1;
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll mod = 1E9 + 7;

	ll n, k, m; cin >> n >> k >> m;

	ll dp[n+1][k+1][1<<m];
	
	for(ll i = 0; i <= n; i++)
		for(ll j = 0; j <= k; j++)
			for(ll mask = 0; mask < (1 << m); mask++)
				dp[i][j][mask] = 0;

	dp[0][0][0] = 1;
	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j <= k; j++)
		{
			for(ll mask = 0; mask < (1 << m); mask++)
			{
				ll nwmask = (mask << 1) % (1 << m);
				dp[i+1][j][nwmask] = (dp[i+1][j][nwmask] + dp[i][j][mask]) % mod;

				nwmask |= 1;

				if(j < k )
				{
					ll cnt = Ones(mask);
					dp[i+1][j+1][nwmask] = (dp[i+1][j+1][nwmask] + (cnt * dp[i][j][mask]) % mod) % mod;
				}
			}
		}
	}			

	ll ans = 0;
	for(ll mask = 0; mask < (1 << m); mask++)
		ans = (ans + dp[n][k][mask]) % mod;

	cout << ans << endl;

	return 0;
}