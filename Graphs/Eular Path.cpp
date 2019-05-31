/*input
20
10 10 8 9 7 4 9 9 8 9 12 1 1 10 19 5 17 5 9
13 19 9 19 9 12 19 19 19 9 19 4 13 10 19 19 19 7 10
*/

//https://codeforces.com/contest/1152/problem/E

#include<bits/stdc++.h>
using namespace std;
vector< multiset<int> > graph;
vector<int> ans;

void dfs(int src)
{
    while(graph[src].size() != 0)
    {
        int v = *(graph[src].begin());
        graph[src].erase(graph[src].begin());
        graph[v].erase(graph[v].find(src));
        dfs(v);
    }

    ans.push_back(src);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    int brr[n], crr[n], i = 0;
    unordered_map<int, int> m;
    vector<int> num;

    for(i = 0; i < n - 1; i++) cin >> brr[i];

    for(i = 0; i < n - 1; i++)
    {
        cin >> crr[i];
        if(brr[i] > crr[i])
        {
            puts("-1");
            return 0;
        }

        if(m.find(brr[i]) == m.end())
        {
            m[brr[i]] = num.size();
            num.push_back(brr[i]);
        }
        if(m.find(crr[i]) == m.end())
        {
            m[crr[i]] = num.size();
            num.push_back(crr[i]);
        }

        crr[i] = m[crr[i]];
        brr[i] = m[brr[i]];
    } 

    graph.assign(num.size(), multiset<int>());

    for(i = 0; i < n - 1; i++)
    {
        graph[brr[i]].insert(crr[i]);
        graph[crr[i]].insert(brr[i]);
    }

    int odd = 0, src = 0;
    for(i = 0; i < num.size(); i++)
        if(graph[i].size() & 1)
            odd++, src = i;

    if(odd == 1 || odd > 2)
    {
        puts("-1");
        return 0;
    }

    dfs(src);

    if(ans.size() < n)
    {
        puts("-1");
        return 0;
    }

    for(auto k : ans)
        cout << num[k] << " ";

    return 0;
}