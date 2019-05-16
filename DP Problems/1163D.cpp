/*input
***
cc
z
*/
// https://codeforces.com/contest/1163/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 101;
string code,s,t;
ll lps_s[N][26], lps_t[N][26];
void lps(string str)
{ 
    ll n = str.size();
    ll lps[n+1];
    lps[0] = 0;
    for(ll i = 1;i<n;i++)
    {
        ll pos = lps[i-1];
        while(pos>0&&str[pos]!=str[i]) pos = lps[pos-1];
        if(str[pos]==str[i]) pos++;
        lps[i] = pos;
    }
    for(ll j = 0;j<=n;j++)
    {
        for(char ch = 'a';ch<='z';ch++)
        {
            ll pos = j;
            while(pos>0&&ch!=str[pos]) pos = lps[pos-1];
            if(str[pos]==ch) pos++;
            if(str==s) lps_s[j][ch-'a'] = pos;
            else lps_t[j][ch-'a'] = pos;
        }
    }
}
int main()
{
    cin>>code>>s>>t;
    lps(s); lps(t);
    ll dp[code.size()+1][s.size()+1][t.size()+1];
    ll n = code.size(),m = s.size(), p = t.size();
    for(ll i = 0;i<=n;i++)
        for(ll j = 0;j<=m;j++)
            for(ll k = 0;k<=p;k++)
                dp[i][j][k] = -1E17;
    dp[0][0][0] = 0;    
    for(ll i = 0;i<n;i++)
    {
        for(ll j = 0;j<=m;j++)
        {
            for(ll k = 0;k<=p;k++)
            {
                for(char ch = 'a';ch<='z';ch++)
                {
                    if(code[i]==ch||code[i]=='*')
                    {
                        ll kmp_s = lps_s[j][ch-'a'];
                        ll kmp_t = lps_t[k][ch-'a'];
                        ll cnt1 = 0;
                        if(kmp_s==m) cnt1++;
                        if(kmp_t==p) cnt1--;
                        ll temp = dp[i][j][k] +  cnt1;
                        dp[i+1][kmp_s][kmp_t] = max(dp[i+1][kmp_s][kmp_t],temp);
                    }
                }
            }
        }
    }
    ll mx = -1E17;
    for(ll i = 0;i<=m;i++)
    {
        for(ll j = 0;j<=p;j++)
        {
            mx = max(mx,dp[n][i][j]);
        }
    }
    cout<<mx;
    return 0;
}