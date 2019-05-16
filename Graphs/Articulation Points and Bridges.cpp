/*input
3 2
0 1
1 2
*/
// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/articulation-points-and-bridges/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
const ll N = 20;
ll n;
vector<ll> graph[N];
set<pair<ll,ll> > bridge;
set<ll> ap;
ll dis[N],vis[N],low[N];
void dfs(ll src, ll time, ll par)
{
    vis[src] = 1;
    dis[src] = low[src] = time + 1;
    ll child = 0;
    for(auto k : graph[src])
    {
        if(vis[k]==false)
        {
            dfs(k,time+1,src);
            low[src] = min(low[src],low[k]);
            child++;
            if(child>=2&&par==-1) ap.insert(src);
            if(par!=-1&&low[k]>=dis[src]) ap.insert(src);
            if(low[k]>dis[src])
            {
                ll fi = src, si = k;
                if(si<fi) swap(fi,si);
                bridge.insert({fi,si});
            }
        }
        else if(k!=par)
        {
            low[src] = min(low[src],dis[k]);
        }
    }
}
int main()
{
    ll m; cin>>n>>m;
    while(m--)
    {
        ll x,y; cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs((ll)0,(ll)0,-1);
    cout<<ap.size()<<endl;
    for(auto k : ap) cout<<k<<" ";
    cout<<endl;
    cout<<bridge.size()<<endl;
    for(auto k : bridge)
    {
        cout<<k.first<<" "<<k.second<<endl;
    }
    return 0;
}