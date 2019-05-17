/*input
4
1 2 2
2 3 3
1 4 1
*/
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/explorers-birthday/description/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 6E5;
ll mod = 1E9 + 7;
ll n,ans = 0;
vector<pair<ll,ll> > graph[N];
ll dfs(ll src, ll par)
{
    ll sum = 0;
    for(auto k : graph[src])
    {
        ll w = k.second;
        ll u = k.first;
        if(u==par) continue;
        ll child = dfs(u,src);
        child = ((child*w)%mod + w)%mod;
        ans = (ans+child)%mod;
        ans =  (ans + (sum*(child))%mod)%mod;
        sum = (sum + child)%mod;
    }
    return sum;
}
int main()
{
    cin>>n;
    for(ll i = 1;i<n;i++)
    {
        ll u,v,w; cin>>u>>v>>w;
        u--; v--;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }
    ll sum = dfs((ll)0,(ll)-1);
    cout<<ans;
    return 0;
}