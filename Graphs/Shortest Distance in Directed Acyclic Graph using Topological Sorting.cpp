/*input
2
9 
4
*/
// https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 20001;
ll n, dist[N], vis[N];
vector<ll> graph[N];
stack<ll> st;

void dfs(ll src)
{
    vis[src] = 1;

    for(auto node : graph[src])
        if(vis[node] == 0)
            dfs(node);

    st.push(src);
}
void shortest_distance(ll src)
{
    for(ll i = 0; i <= n; i++) dist[i] = 1E12;
    dist[src] = 0;

    while(!st.empty())
    {
        ll u = st.top();
        st.pop();
        if(dist[u] == 1E12) continue;
        for(auto node : graph[u])
            if(dist[node] > dist[u] + 1)
                dist[node] = dist[u] + 1;
    }
}
int main()
{
    ll t; cin >> t;
    while(t--)
    {
        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            vis[i] = 0;
            graph[i].clear();
            if((i + 1) <= n) graph[i].pb(i+1);
            if((3 * i) <= n ) graph[i].pb(3*i);
        }
                
        dfs((ll)1);

        shortest_distance((ll)1);

        if(dist[n] == 1E12) dist[n] = 0;

        cout << dist[n] << endl;
    }
    return 0;
}