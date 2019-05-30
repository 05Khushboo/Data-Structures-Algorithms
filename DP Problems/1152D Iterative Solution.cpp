/*input
1000
*/
// https://codeforces.com/contest/1152/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 1002;
ll dp[N][N];
ll mod = 1E9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;

    for(ll open = n; open >= 0; open--)
        for(ll close = open; close >= 0; close--)
            dp[open][close] = (dp[open+1][close] + dp[open][close+1] + ((open + close) & 1))%mod;

    cout << dp[0][0] << endl;

    return 0;
}