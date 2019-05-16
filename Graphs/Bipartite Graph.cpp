
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
#define ll int
bool isBipartite(int G[][MAX],int n)
{
    ll V = n;
    ll col[V];
    for(ll i = 0;i<V;i++) col[i] = -1;
    for(ll j = 0;j<V;j++)
    {
        if(col[j]==-1)
        {
            queue<ll> q;
            q.push(j);
            col[j] = 0;
            while(!q.empty())
            {
                ll top = q.front();
                q.pop();
                if(G[top][top]) return false;
                for(ll i = 0;i<V;i++)
                {
                    if(G[top][i])
                    {
                        if(col[i]==col[top]) return false;
                        else if(col[i]==-1)
                        {
                            if(col[top]==0) col[i] = 1;
                            else col[i] = 0;
                            q.push(i);
                        }
                    }
                }
            }
        }
    }
    return true;
}