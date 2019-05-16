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
ll kruskal()
{
	for(ll i = 0;i<n;i++) par[i] = i;
	ll total = 0;
	for(ll i = 0;i<edge.size();i++)
	{
		ll u = edge[i].second.first;
		ll v = edge[i].second.second;
		ll w = edge[i].first;
		if(find(u)!=find(v))
		{
			total+=w;
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
	sort(edge.begin(),edge.end());
	cout<<kruskal()<<endl;
	return 0;
}