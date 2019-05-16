#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define pb push_back
struct Trie 
{ 
    Trie* node[2]; 
    bool valid; 
}; 
bool check(ll N, ll i) 
{ 
    return (bool)(N & (1<<i)); 
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
    for (ll i = 31; i >= 0; i--) 
    { 
        ll f = check(x, i); 
        if (! Tr->node[f]) 
            Tr->node[f] = newNode(); 
        Tr = Tr->node[f]; 
    } 
    Tr->valid = true; 
}   
ll findvalue(Trie *root, ll x) 
{ 
    Trie* Tr = root;   
    ll ans = 0; 
    for (ll i = 31; i >= 0; i--) 
    { 
        ll f = check(x, i); 
        if ((Tr->node[f ^ 1])) 
        { 
            ans = ans + (1 << i); 
            Tr = Tr->node[f ^ 1]; 
        } 
        else
            Tr = Tr->node[f]; 
    } 
 
    return ans; 
}   
bool isEmpty(Trie* root) 
{ 
    for (int i = 0; i < 2; i++) 
        if (root->node[i]) 
            return false; 
    return true; 
} 
Trie* remove(Trie* root, vector<ll> key, ll depth) 
{ 
    if (!root) 
    {
        return NULL;   
    }
    if (depth == key.size()) {   
        if (root->valid) 
            root->valid = false; 
          if (isEmpty(root)) { 
            delete (root); 
            root = NULL; 
        } 
        return root; 
    } 
    ll index = key[depth]; 
    root->node[index] =  
          remove(root->node[index], key, depth + 1); 
    if (isEmpty(root) && root->valid == false) { 
        delete (root); 
        root = NULL; 
    } 
    return root; 
} 
void del(Trie *root, ll no)
{
    vector<ll> v;
    for(ll i = 31;i>=0;i--)
    {
        if(check(no,i)) v.pb(1);
        else v.pb(0);
    }
    remove(root,v,(ll)0); 
}   
int main() 
{ 
    Trie* root = newNode(); 
    insert(root, (ll)10); 
    insert(root, (ll)13); 
    cout << findvalue(root, (ll)10) << endl; 
    insert(root, (ll)9); 
    insert(root, (ll)5); 
    cout << findvalue(root, (ll)6) << endl; 
    del(root,(ll)9); 
    del(root,(ll)5); 
    cout << findvalue(root, 10) << endl;
    return 0; 
} 