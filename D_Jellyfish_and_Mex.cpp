#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define aint(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (int i = a; i < b; i++)
#define MOD (int)(1e9 + 7)
#define mod (int)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
int dijkstra(vector<vector<pii>>& adj , int source , int destination)
{
    vi distance(source + 1 , INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii> > q;
    vb visited(source+1,false);
    distance[source] = 0; 
    visited[source] = 0;
    q.push({0,source});
    while(!q.empty())
    {
        pii top = q.top();
        q.pop();
        if(distance[top.ss]<top.ff || visited[top.ss])
        {
            continue;
        }
        visited[top.ss] = 1;
        for(auto x : adj[top.ss])
        {
            if(!visited[x.ff])
            {
                if(distance[x.ff] > distance[top.ss] + x.ss)
                {

                    distance[x.ff] = min<int>(distance[x.ff] , distance[top.ss] + x.ss);
                    q.push({distance[x.ff],x.ff});
                }
            }
        }
    }
    return distance[0];
}
void solve()
{
    int n;
    cin >> n;
    vi count(5001,0);
    int mex = 0;
    REP(i,0,n)
    {
        int ele;cin>>ele;
        if(ele<=5000)
        count[ele]++;
    }
    REP(i,0,5001)
    {
        if(count[i]>0)
        mex++;
        else
        break;
    }

    vector<vector<pii>> adj(mex+1);
    for(int i=mex;i>=0;i--) // from i to j
    {
        for(int j=i-1;j>=0;j--)
        {
            int weight = (count[j]-1)*(i) + j;
            adj[i].pb({j,weight}); 
        }
    }
    cout<<dijkstra(adj,mex,0);
    return;
}
int main()
{
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        solve(); 
        cout << endl;
    }
    return 0;
}
