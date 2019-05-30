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
ll dp[N][N], n;
ll mod = 1E9 + 7;
ll rec(ll open, ll close)
{
    if(close > open || open > n || close > n) return 0; 

    if(open == n && close == n) {
        dp[n][n] = 0;
        return 0;
    }

    if(dp[open+1][close] == -1) dp[open+1][close] = rec(open + 1, close);
    if(dp[open][close+1] == -1) dp[open][close+1] = rec(open, close + 1);

    dp[open][close] = (dp[open+1][close] + dp[open][close+1])%mod;

    if((open + close) & 1) dp[open][close] = (dp[open][close] + (ll)1)%mod;

    return dp[open][close];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(ll i = 0; i <= (n + 1); i++)
        for(ll j = 0; j <= (n + 1); j++)
            dp[i][j] = -1;

    rec(0, 0);   
    cout << dp[0][0] << endl;

    return 0;
}