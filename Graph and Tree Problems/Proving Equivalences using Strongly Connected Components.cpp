/*input
1
6 6
1 2
2 3
3 1
4 5
5 6
6 4
*/
// https://www.spoj.com/problems/PMATRIX/
// https://open.kattis.com/problems/equivalences
// https://www.youtube.com/watch?v=z9oOadBgO9I
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
    ll t; cin >> t;
    while(t--)
    {
        cin >> n >> m; 

        tim = 0, All_SCC.clear();
        ll parent[n], indegree[n], outdegree[n];
        for(ll i = 0; i < n; i++)
        {
            graph[i].clear();
            vis[i] = 0;
            indegree[i] = outdegree[i] = 0;
            parent[i] = -1;
        }

        while(m--)
        {
            ll u, v; cin >> u >> v;
            graph[--u].pb(--v);
        }

        strongly_connected_components();

        ll idx = 0;
        for(auto scc : All_SCC)
        {
            for(auto node : scc) parent[node] = idx;
            idx++; 
        }

        for(ll i = 0; i < n; i++)
            for(auto node : graph[i])
                if(parent[i] != parent[node]) 
                    outdegree[parent[i]]++, indegree[parent[node]]++;

        ll indeg = 0, outdeg = 0;
        for(ll i = 0; i < idx; i++) 
        {
            if(indegree[i] == 0) indeg++;
            if(outdegree[i] == 0) outdeg++;
        }

        if(All_SCC.size() == 1) cout << 0 <<endl;
        else cout << max(indeg, outdeg) << endl;

    }

    return 0;
}