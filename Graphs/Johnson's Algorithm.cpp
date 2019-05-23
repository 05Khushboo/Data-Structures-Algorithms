/*input
6
2 2
1 2 -2
2 1 1
6 8
1 2 8
1 6 6
6 2 3
2 3 -1
3 6 -2
6 5 -2
5 4 2
3 4 3
4 4
1 2 1
2 3 2
3 4 3
4 1 0
2 0
1 0
2 2
1 2 -1
2 1 0
*/
// https://www.spoj.com/problems/JHNSN/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 1001;
ll n, m, dist[N], vis[N], H[N];
vector<pair<ll, ll > > graph[N];
vector<pair<pair<ll, ll>, ll > > edges;
ll shortest_path[N][N];

void clear_everything()
{

    edges.clear();
    for(ll i = 0; i <= n; i++) 
    {
        graph[i].clear();
        dist[i] = 1E12;
        vis[i] = 0;
        H[i] = 0;
    }
    for(ll i = 0; i <= n; i++)
        for(ll j = 0; j <= n; j++)
            shortest_path[i][j] = 1E12;
}
bool bellman_check(ll edge_idx)
{
    ll u = edges[edge_idx].first.first;
    ll v = edges[edge_idx].first.second;
    ll w = edges[edge_idx].second;

    if(dist[v] > (dist[u] + w))
    {
        dist[v] = dist[u] + w;
        return true;
    }

    return false;
}
bool bellman_ford(ll src)
{
    dist[src] = 0;
    for(ll i = 0; i <= (n + 1); i++)
        for(ll j = 0; j < edges.size(); j++)
            if(bellman_check(j) && i == (n+1))
                return true;

    return false;
}
void update_weight_values()
{
    graph[n].clear();
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < graph[i].size(); j++)
        {
            ll u = i;
            ll v = graph[i][j].first;
            graph[i][j].second += (dist[u] - dist[v]);
        }
    }
    
    for(ll i = 0; i <= n; i++) H[i] = dist[i], cout << dist[i] << " ";
    cout << endl << endl;
}
void dijkstra(ll src)
{
    for(ll i = 0; i < n; i++) vis[i] = 0, dist[i] = 1E12;
    dist[src] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq; 
    pq.push({(ll)0, src});

    while(!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto k : graph[u])
        {
            ll v = k.first;
            ll w = k.second;
            if(!vis[v] && dist[v] > (dist[u] + w))
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(ll i = 0; i < n; i++)
        shortest_path[src][i] = (dist[i] == 1E12) ? dist[i] : dist[i] - (H[src] - H[i]);  
}
void print_all_distances()
{
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(shortest_path[i][j] == 1E12) cout << "#" << " ";
            else cout << shortest_path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{   
    ll t; cin >> t;
    for(ll idx = 1; idx <= t; idx++)
    {
        cin >> n >> m;
        clear_everything();
        for(ll i = 0; i < m; i++)
        {
            ll u, v, w; cin >> u >> v >> w;
            u--; v--;
            graph[u].pb({v, w});
            edges.pb({{u, v}, w});
        }
        for(ll i = 0; i < n; i++)
        {
            graph[n].pb({i, (ll)0});
            edges.pb({{n, i}, (ll)0});
        }
        if(bellman_ford(n)) // if the graph has negative weight cycles.
        {
            cout << "graph " << idx << " no" << endl << endl;
            continue;
        }

        cout << "graph " << idx << " yes" << endl << endl;
        update_weight_values();

        for(ll i = 0; i < n; i++)
            dijkstra(i);
            
        print_all_distances();
    }    
    return 0;
}