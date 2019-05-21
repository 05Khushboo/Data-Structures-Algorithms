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
vector<ll> graph[N];
ll disc[N], low[N], tim = 0;
stack<ll> st;
vector<vector<ll> > All_SCC;
bitset<N> vis;

void dfs(ll src)
{
    vis[src] = 1;
    disc[src] = low[src] = tim++;
    st.push(src);

    for(auto node : graph[src])
    {
        if(disc[node] == -1)
        {
            dfs(node);
            low[src] = min(low[src], low[node]);
        }
        else if(vis[node] == 1)
            low[src] = min(low[src], disc[node]);
    }

    if(low[src] == disc[src])
    {
        vector<ll> scc;
        while(st.top() != src)
        {
            ll top = st.top();
            vis[top] = 0;
            scc.pb(top);
            st.pop();
        }
        vis[st.top()] = 0;
        scc.pb(st.top()); All_SCC.pb(scc);
        st.pop();
    }
    
}

void strongly_connected_components()
{
    for(ll i = 0; i < n; i++) 
        disc[i] = low[i] = -1;

    for(ll i = 0; i < n; i++)
        if(disc[i] == -1)
            dfs(i);
}
int main()
{
    cin >> n >> m; 
    while(m--)
    {
        ll u, v; cin >> u >> v;
        u--; v--;
        graph[u].pb(v);
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