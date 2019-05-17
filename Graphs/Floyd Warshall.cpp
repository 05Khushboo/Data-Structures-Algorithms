/*input
1
5
0 149 10000000 10000000 10000000
10000000 0 350 330 10000000
165 10000000 0 10000000 10000000
10000000 232 219 0 10000000
241 10000000 10000000 484 0
*/
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
ll INF = 1E7;

int main()
{
    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll graph[n][n];

        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < n; j++)
            {
                ll x; cin >> x;
                graph[i][j] = x;
            }
        }

        for(ll k = 0; k < n; k++)
            for(ll i = 0; i < n; i++)
                for(ll j = 0; j < n; j++)
                    if( graph[i][j] > (graph[i][k] + graph[k][j]) )
                        graph[i][j] = graph[i][k] + graph[k][j];

        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < n; j++)
            {
                if(graph[i][j] == INT_MAX || graph[i][j] == INF) 
                    cout << "INF" << " ";
                else 
                    cout << graph[i][j] << " ";
            }
            cout << endl;
        }   
    }           
    return 0;
}