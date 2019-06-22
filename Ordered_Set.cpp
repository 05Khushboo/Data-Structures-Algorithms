/*input
1
4
13 18
10 20
15 22
16 19
*/
// https://www.codechef.com/ZCOPRAC/problems/SINGTOUR
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll int
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		pair<pair<ll,ll>, ll> arr[n];
		ll ans[n];
		for(ll i = 0; i < n; i++)
		{
			ans[i] = 0;
			cin >> arr[i].first.first >> arr[i].first.second;
			arr[i].second = i;
		}
		sort(arr, arr + n);
		ordered_set s;
		for(auto k : arr)
		{
			ans[k.second] += s.order_of_key(k.first.second);
			s.insert(k.first.second);
		}
		s.clear();
		for(ll i = n - 1; i >= 0; i--)
		{
			auto k = arr[i];
			ll val = s.order_of_key(k.first.second);
			ans[k.second] += 2 * val + s.size() - val;
			s.insert(k.first.second);
		}
		for(auto k : ans)
			cout << k << " ";
		cout << endl;
	}

	
	return 0;
}