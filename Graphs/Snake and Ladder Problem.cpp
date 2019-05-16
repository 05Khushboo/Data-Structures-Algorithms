/*input
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30
*/
// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main()
{
    ll t; cin>>t;
    while(t--)
    {
		ll n, pos[31];
		cin>>n;
		for(ll i = 0;i<31;i++) pos[i] = -1;
    	for(ll i = 0;i<n;i++)
    	{
    		ll a,b; cin>>a>>b;
    		pos[a] = b;
    	}
    	queue<pair<ll,ll> > q;
    	q.push({1,0});
    	ll vis[31],ans = 0;
    	for(ll i = 0;i<31;i++) vis[i] = 0;
    	while(!q.empty())
    	{
    		ll top = q.front().first;
    		ll dis = q.front().second;
    		q.pop();
    		if(top==30) 
    		{
    			ans = dis;
    			break;
    		}
    		if(vis[top]) continue;
    		vis[top] = 1;
    		// cout<<top<<" ";
    		for(ll j = 1;j<=6;j++)
    		{
    			if((top+j)<=30&&vis[top+j]==0)
    			{
    				ll b;
    				if(pos[top+j]==-1)
    				{
    					b = top + j;
    				}
    				else b = pos[top+j];
    				q.push({b,dis+1});
    			}
    		}
    	}
    	cout<<ans<<endl;
    }
	return 0;
}