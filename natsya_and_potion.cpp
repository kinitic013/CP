#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void dfs(vector<vi> &adj,vector<bool> &visited,stack<ll> &s,ll node)
{
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            dfs(adj,visited,s,adj[node][i]);
        }
    }
    s.push(node);
}
vi topo_order(vector<vi> adj)
{
    vi order;
    ll n=adj.size()-1;
    vector<bool > visited(n+1,false);
    stack<ll> s;
    //for 1 base graph
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,s,i);
        }
    }
    while(!s.empty())
    {
        order.push_back(s.top());
        s.pop();
    }
    reverse(all(order));
    return order;
}
void  solve()
{
    ll n,k;cin>>n>>k;
    vi price(n+1);
    set<ll> free;
    REP(i,1,n+1) cin>>price[i];
    REP(i,0,k) 
    {
        ll ele;cin>>ele;
        free.insert(ele);
    }

    vi result(n+1,LONG_LONG_MAX);
    vector<vi> adj(n+1);
    REP(i,1,n+1)
    {
        ll m;cin>>m;
        REP(j,0,m)
        {
            ll ele;cin>>ele;
            adj[i].pb(ele);
        }
    }
    vi topo=topo_order(adj);
    REP(i,0,topo.size())
    {
        ll top=topo[i];
        auto add=free.find(top);
        if(add!=free.end())//found
        {
            result[top]=0;
            continue;
        }
        ll curr=LONG_LONG_MAX;
        REP(j,0,adj[top].size())
        {
            if(j==0)
            curr=0;

            curr+=result[adj[top][j]];
        }
        result[top]=min(price[top],curr);
    }
    REP(i,1,n+1)
    {
        cout<<result[i]<<" ";
    }
    return;
}
int main()
{
    fast();
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
