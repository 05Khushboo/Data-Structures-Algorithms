/*input
2
5 8
0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
3 3
0 1 -5 1 2 -6 2 0 -9
*/
// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 1E6;
ll n, e, dist[N];
vector<pair<pair<ll, ll>, ll> > edge;

bool bellman_check(ll edge_idx)
{
    ll u = edge[edge_idx].first.first;
    ll v = edge[edge_idx].first.second;
    ll w = edge[edge_idx].second;

    if(dist[v] > (dist[u] + w)) 
    {
        dist[v] = dist[u] + w;
        return true;
    }

    return false;
}

bool bellman_ford(ll src)
{
    for(ll i = 0; i < n; i++) dist[i] = 1E17;
    dist[src] = 0;

    for(ll i = 1; i <= n; i++)
        for(ll j = 0; j < e; j++)
            if(bellman_check(j) && i == n) return true;

    return false;
}
int main()
{
    ll t; cin >> t;
    while(t--)
    {
        edge.clear();
        cin >> n >> e;
        for(ll i = 0; i < e; i++)
        {
            ll u, v, w; cin >> u >> v >> w;

            edge.pb({{u, v}, w});
        }

        ll src = 0;
        if(bellman_ford(src)) cout << 1 << endl;
        else cout << 0 << endl;
    }   
    return 0;
}