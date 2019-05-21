/*input
5 6
1 4
1 3
2 4
3 4
4 5
5 1
*/
// https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 5E5;
ll n, m;
vector<ll> graph[N], Tgraph[N];
ll vis[N];
stack<ll> st;
vector<vector<ll> > All_SCC;

void dfs(ll src)
{
    vis[src] = 1;

    for(auto node : graph[src])
        if(vis[node] == 0)
            dfs(node);

    st.push(src);
}

void Tdfs(ll src, vector<ll> &scc)
{
    vis[src] = 1;
    scc.pb(src);

    for(auto node : Tgraph[src])
        if(vis[node] == 0)
            Tdfs(node, scc);
}
void strongly_connected_components()
{
    for(ll i = 0; i < n; i++) vis[i] = 0;

    for(ll i = 0; i < n; i++)
        if(vis[i] == 0)
            dfs(i);

    for(ll i = 0; i < n; i++) vis[i] = 0;

    while(!st.empty())
    {
        ll top = st.top();
        st.pop();
        if(vis[top] == 1) continue;
        else
        {
            vector<ll> scc;
            Tdfs(top, scc);
            All_SCC.pb(scc);
        }
    }
}
int main()
{
    cin >> n >> m; 
    while(m--)
    {
        ll u, v; cin >> u >> v;
        u--; v--;
        graph[u].pb(v);
        Tgraph[v].pb(u);
    }
    strongly_connected_components();

    ll odd = 0, even = 0;
    for(auto scc : All_SCC)
    {
        if(scc.size() & 1) odd += scc.size();
        else even += scc.size();
    }

    cout << odd - even << endl;
    return 0;
}