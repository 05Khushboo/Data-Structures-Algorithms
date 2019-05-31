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
const ll N = 1E5 + 5, K = 13, M = 4;
ll dp[N][K][1 << M];
ll n, k, m;
ll mod = 1E9 + 7;

ll rec(ll pid, ll kid, ll mask)
{
	// cout << pid << " " << kid << " " << mask << endl;
	if(kid == 0) return 1;
	if(pid <= 0) return 0;
	if(pid < kid) return 0;

	if(dp[pid][kid][mask] != -1) return dp[pid][kid][mask];

	ll ans = 0;

	ll nwmask = (mask << 1) % (1 << m);
	ans = rec(pid - 1, kid, nwmask);

	nwmask |= 1;
	ans = (ans + rec(pid - 1, kid - 1, nwmask)) % mod;

	for(ll i = 0; i < m; i++)
	{
		if(mask & (1 << i))
		{
			nwmask = (mask << 1) % (1 << m);
			nwmask |= 1;
			ans = (ans + rec(pid - 1, kid - 1, nwmask)) % mod;
		}
	}

	dp[pid][kid][mask] = ans;

	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> k >> m;

	for(ll i = 0; i <= n; i++)
		for(ll j = 0; j <= k; j++)
			for(ll p = 0; p < (1 << m); p++)
				dp[i][j][p] = -1;

	ll mask = 0;

	cout << rec(n, k, mask) << endl;


	return 0;
}