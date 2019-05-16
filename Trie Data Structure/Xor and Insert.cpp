/*input
10
3
1 7
3
2 4
2 8
2 3
1 10
1 3
3
2 1
*/
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/
#include<bits/stdc++.h> 
using namespace std; 
#define ll int
#define pb push_back
#define mp make_pair
struct Trie 
{ 
    Trie* node[2]; 
    bool valid; 
}; 
ll pw[35];
void power()
{
    ll p = 1;
    for(ll i = 0;i<=32;i++)
    { 
        pw[i] = p;
        p*=2;
    }
}
bool check(ll N, ll i) 
{ 
    ll val = pw[i];
    val = N&val;
    return val; 
}   
Trie* newNode() 
{ 
    Trie* temp = new Trie; 
    temp->valid = false; 
    temp->node[0] = NULL; 
    temp->node[1] = NULL; 
    return temp; 
}   
void insert(Trie* root, ll x) 
{ 
    Trie* Tr = root; 
    for (ll i = 32; i >= 0; i--) 
    { 
        ll f = check(x, i); 
        if (Tr->node[f]==NULL) 
            Tr->node[f] = newNode(); 
        Tr = Tr->node[f]; 
    } 
    Tr->valid = true;
}   
ll fv(Trie *root, ll x) 
{ 
    Trie* Tr = root;   
    ll ans = 0; 
    vector<ll> v;
    for (ll i = 32; i >= 0; i--) 
    { 
        ll f = check(x, i); 
        if ((Tr->node[f])) 
        { 
            Tr = Tr->node[f]; 
            v.pb(0);
        } 
        else
        {
            f = f^1;
            v.pb(1);
            Tr = Tr->node[f]; 
        }
        if(Tr->valid) break;
    }
    reverse(v.begin(),v.end());
    for(ll i = 0;i<v.size();i++)
    {
        if(v[i]==1) ans = ans + pw[i];
    } 
    return ans; 
}   
int main() 
{ 
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     power();
    ll t; cin>>t;
    Trie *root = newNode();
    insert(root,0);
    ll y = 0;
    while(t--)
    {
        ll type; cin>>type;
        if(type==1)
        {
            ll x; cin>>x;
            x^=y;
            insert(root,x);
        } 
        else if(type==2)
        {
            ll x; cin>>x;
            y = y^x;
        }
        else
        {
            ll ans = fv(root,y);
            cout<<ans<<endl;
        }
    }
    return 0; 
} 
