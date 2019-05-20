/*input
2
3
1 2 3 1 5 6
3
1 2 4 4 5 1
*/
// https://practice.geeksforgeeks.org/problems/convex-hull/0
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
#define pb push_back
#define mp make_pair
#define x first
#define y second
pair<ll, ll> point0; 
vector<pair<ll, ll> > polygon;

pair<ll, ll> nextToTop(stack<pair<ll, ll> > st) 
{
    st.pop();
    return st.top();
}
ll orientation(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
    ll val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

    if(val == 0) return 0;
    return val < 0 ? 1 : -1; 
}
ll distance(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
}
bool cmp(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
    ll orient = orientation(point0, p1, p2);
    if(orient == 0) return distance(point0, p1) < distance(point0, p2);
    return (orient == -1);
}
void Convex_Hull(pair<ll, ll> points[], ll n)
{
    if(n < 3) return ;
    point0 = points[0];
    ll idx = 0;
    for(ll i = 1; i < n; i++)
    {
        if(point0.y > points[i].y) 
            point0 = points[i], idx = i;
        else if(point0.y == points[i].y && point0.x > points[i].x) 
            point0 = points[i], idx = i;
    }
    swap(points[0], points[idx]);
    sort(points + 1, points + n, cmp);

    ll m = 1;
    for(ll i = 1; i < n; i++)
    {
        while( (i < (n-1)) && orientation(point0, points[i], points[i+1]) == 0) i++;

        points[m++] = points[i];
    }

    if(m < 3) return ;

    stack<pair<ll, ll> > st;
    st.push(points[0]), st.push(points[1]), st.push(points[2]);

    for(ll i = 3; i < m; i++)
    {
        pair<ll, ll> p1 = nextToTop(st), p2 = st.top(), p3 = points[i];
        while(orientation(p1, p2, p3) != -1)
        {
            st.pop();
            p2 = p1;
            p1 = nextToTop(st);
        }
        st.push(p3);
    }

    while(!st.empty())
    {
        polygon.pb(st.top());
        st.pop();
    }

}
int main()
{   
    ll t; cin >> t;
    while(t--)
    {
        polygon.clear();

        ll n; cin >> n;

        pair<ll,ll> points[n];
        for(ll i = 0; i < n; i++) 
            cin >> points[i].x >> points[i].y;

        Convex_Hull(points, n);

        if(polygon.size() == 0) cout << -1 <<endl;
        else
        {
            sort(polygon.begin(), polygon.end());  
            cout << polygon[0].x << " " << polygon[0].y; 
            for(ll i = 1; i < polygon.size(); i++)
                cout << ", "<<polygon[i].x << " " << polygon[i].y;
            cout << endl;
        }
    }   
    return 0;
}