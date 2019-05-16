/*input
4 4
0 1
1 2
2 3
3 1
*/
// https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/practice-problems/algorithm/biconnected-components/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
const ll N = 101;
ll n,disc[N],vis[N],low[N];
vector<ll> graph[N];
stack<pair<ll,ll> > s;
set<ll> bcp;
ll odd = 0, even = 0;
void dfs(ll src, ll time, ll par)
{
	ll child = 0;
	vis[src] = 1;
	disc[src] = low[src] = time + 1;
	for(auto k : graph[src])
	{
		if(vis[k]==0)
		{
			s.push({src,k});
			dfs(k,time+1,src);
			low[src] = min(low[src],low[k]);
			child++;
			if(par==-1&&child>=2) 
			{
				while(s.top().first!=src||s.top().second!=k)
				{
					bcp.insert({s.top().first});
					bcp.insert({s.top().second});
					s.pop();
				}
				bcp.insert(src); bcp.insert(k);
				s.pop();
				if(bcp.size()%2!=0) odd++;
				else even++;
				bcp.clear();
			}
			if(par!=-1&&low[k]>=disc[src]) 
			{	
				while(s.top().first!=src||s.top().second!=k)
				{
					bcp.insert({s.top().first});
					bcp.insert({s.top().second});
					s.pop();
				}
				bcp.insert(src); bcp.insert(k);
				s.pop();
				if(bcp.size()%2!=0) odd++;
				else even++;
				bcp.clear();
			}
		}
		else if(par!=k)
		{
		    if(low[src]>disc[k]) s.push({src,k});
			low[src] = min(low[src],disc[k]);
			
		}
	}
}
int main()
{
 
	ll e; cin>>n>>e;
	for(ll i = 0;i<=n;i++) vis[i] = 0;	
	while(e--)
	{
		ll x,y; cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	for(ll i = 0;i<n;i++)
	{
		if(vis[i]==0)
		{
			dfs((ll)i,(ll)0,-1);
			while(!s.empty())
			{
				bcp.insert({s.top().first});
				bcp.insert({s.top().second});
				s.pop();
			}
			if(bcp.size()%2!=0) odd++;
			else even++;
			
			bcp.clear();
		}
	}
	cout<<odd<<" "<<even;
	return 0;
}