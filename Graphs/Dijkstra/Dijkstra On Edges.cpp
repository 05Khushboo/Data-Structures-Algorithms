/*input
4 4
1 2 1
2 3 1
3 4 1
1 3 1
1
4
1 4
*/
//https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/minimum-valid-path-3dc5bd03/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 6E5;
ll n,m;
ll spclnode[N], dis[N][2];
vector<pair<ll,ll> > edge;
vector<ll> node[N];
ll X,Y;
ll dijkstra() //In this question we are applying dijkstra on Edges 
{
//first value is total weight, 2nd value is edge number & 3rd value is total special value
    priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > > pq; 
    pq.push({(ll)0,{m,spclnode[X]}});
    dis[m][spclnode[X]] = 0;
    while(!pq.empty())
    {
       ll total_weight = pq.top().first;
       ll src_idx = pq.top().second.first;
       ll special = pq.top().second.second;
       pq.pop();
       ll u1 = edge[src_idx].first;
       ll w1 = edge[src_idx].second;
       if(u1==Y&&special==1) return total_weight;
       for(auto edge_idx : node[u1])
       {
            ll u2 = edge[edge_idx].first;
            ll w2 = edge[edge_idx].second;
            ll total_special = special + spclnode[u2];
            if(total_special>=2) continue;
            if((2*w2>=w1&&w2<=2*w1)||src_idx==m)
            {
                ll new_weight = total_weight + w2;
                if(dis[edge_idx][total_special]>new_weight)
                {
                    dis[edge_idx][total_special] = new_weight;
                    pq.push({new_weight,{edge_idx,total_special}});
                }
            }
       }
    }
    return -1;
}
int main()
{
    cin>>n>>m;
    for(ll i = 0;i<n;i++)
    {
        spclnode[i] = 0;
    }
    for(ll i = 0;i<=m;i++)
    {
        dis[i][0] = dis[i][1] = 1E17;
    }
    for(ll i = 0;i<m;i++)
    {
        ll u,v,w; cin>>u>>v>>w;
        u--; v--;
        node[u].pb(i);
        edge.pb({v,w});
    }
    ll k; cin>>k;
    for(ll i = 0;i<k;i++)
    {
        ll x; cin>>x;
        x--;
        spclnode[x] = 1;
    }
    cin>>X>>Y;
    X--; Y--;
    edge.pb({X,0}); // Add one more edge from X to X having weight 0;
    cout<<dijkstra();
    return 0;
}