/*input
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
*/
// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 1E5;
vector<pair<ll,ll> > graph[N];
ll n,m;
ll prim()
{
	ll vis[n];
	for(ll i = 0;i<n;i++) vis[i] = 0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	pq.push({0,0}); 
	ll total = 0;
	while(!pq.empty())
	{
		ll u = pq.top().second;
		ll w = pq.top().first;
		pq.pop();
		if(vis[u]) continue;
		total+=w;
		vis[u] = 1;
		for(auto k : graph[u])
		{
			if(vis[k.first]==0)
			{
				pq.push({k.second,k.first});
			}
		}
	}
	return total;
}
int main()
{
	cin>>n>>m;	
	while(m--)
	{
		ll a,b,w; cin>>a>>b>>w;
		a--; b--;
		graph[a].pb({b,w});
		graph[b].pb({a,w});
	}
	cout<<prim();
	return 0;
}
