/*input
3
2 1
0 1
5 6
1 0 0 2 2 1 0 3 3 4 2 4
3 2
0 1 1 2
*/
// https://practice.geeksforgeeks.org/problems/biconnected-graph/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 101;
set<ll> ap;
ll n,disc[N],vis[N],low[N];
vector<ll> graph[N];
void dfs(ll src, ll time, ll par)
{
	ll child = 0;
	vis[src] = 1;
	disc[src] = low[src] = time + 1;
	for(auto k : graph[src])
	{
		if(vis[k]==0)
		{
			dfs(k,time+1,src);
			low[src] = min(low[src],low[k]);
			if(par==-1&&child>=2) ap.insert(src);
			if(par!=-1&&low[k]>=disc[src]) ap.insert(src);
		}
		else if(par!=k)
		{
			low[src] = min(low[src],disc[k]);
		}
	}
}
int main()
{
	ll t; cin>>t;
	while(t--)
	{
		ll e; cin>>n>>e;
		for(ll i = 0;i<=n;i++)
		{
			vis[i] = 0;
			graph[i].clear();
		}
		ap.clear();
		while(e--)
		{
			ll x,y; cin>>x>>y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		dfs((ll)0,(ll)0,(ll)-1);
		if(ap.size()!=0) cout<<0<<endl;
		else
		{
			ll flag = 0;
			for(ll i = 0;i<n;i++)
			{
				if(vis[i]==0)
				{
					flag = 1;
					break;
				}
			}
			if(flag) cout<<0<<endl;
			else cout<<1<<endl;
		}
	}	
	return 0;
}