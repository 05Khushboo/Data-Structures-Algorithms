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
vector<pair<ll,pair<ll,ll> > > edge;
ll n,m;
ll par[N];
ll find(ll x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}
ll boruvka()
{
	ll cheap[n];
	for(ll i = 0;i<n;i++) par[i] = i;
	ll total = 0, comp = n;
	while(comp>1)
	{
		for(ll i = 0;i<n;i++) cheap[i] = -1;
		for(ll i = 0;i<edge.size();i++)
		{
			ll u = edge[i].second.first;
			ll v = edge[i].second.second;
			if(find(u)==find(v)) continue;
			if(cheap[find(u)]==-1) cheap[find(u)] = i;
			else if(edge[cheap[find(u)]].first>edge[i].first) cheap[find(u)] = i;
			if(cheap[find(v)]==-1) cheap[find(v)] = i;
			else if(edge[cheap[find(v)]].first>edge[i].first) cheap[find(v)] = i;
		}
		for(ll i = 0;i<n;i++)
		{
			ll idx = cheap[i];
			if(idx==-1) continue;
			ll u = edge[idx].second.first;
			ll v = edge[idx].second.second;
			if(find(u)==find(v)) continue;
			comp--;
			total+=edge[idx].first;
			par[find(v)] = par[find(u)];
 
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
		edge.pb({w,{a,b}});
	}
	cout<<boruvka()<<endl;
	return 0;
}
