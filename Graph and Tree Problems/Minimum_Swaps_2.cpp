/*input
4
4 3 1 2
*/
// https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    ll n; cin >> n;
    ll arr[n], vis[n], pos[n], sum = 0;
    vector<pair<ll,ll> > sortedarr;

    for(ll i = 0; i < n; i++) 
    {
        cin >> arr[i];
        sortedarr.pb({arr[i],i});
    }
    sort(sortedarr.begin(),sortedarr.end(),cmp);

    for(ll i = 0; i < n; i++)
    {
        vis[i] = 0;
        pos[sortedarr[i].second] = i;
    }

    for(ll i = 0; i < n; i++) 
    {
        if(vis[i]) continue;

        if(pos[i] == i)
        {
            vis[i] = 1;
            continue;
        }

        ll cycle_cnt = 0, newpos = i;
        while(!vis[newpos])
        {
            vis[newpos] = 1;
            cycle_cnt++;
            newpos = pos[newpos];
        }
        cycle_cnt--;
        sum += cycle_cnt;
    }
    cout<<sum;
    return 0;
}