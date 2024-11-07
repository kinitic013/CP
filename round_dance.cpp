#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vb vector<bool>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
void dfs(vector<set<ll>> &adj , vb&visited , int node , bool &flag)
{
    if(adj[node].size()!=2)
    flag=false;

    if(visited[node])
    return;
    visited[node]=1;
    auto it = adj[node].begin();
    while(it!=adj[node].end())
    {
        if(!visited[*it])
        dfs(adj,visited,*it , flag);

        it++;
    }
    return;
}
void solve()
{
    int n;cin>>n;
    vector<set<ll>> adj(n);
    vi arr(n);
    REP(i,0,n)
    {
        cin>>arr[i];
        adj[i].insert(arr[i]-1);
        adj[arr[i]-1].insert(i);
    }
    vb visited(n,false);
    ll complete=0;
    ll incomplete=0;

    REP(i,0,n)
    {
        bool flag= true;
        if(!visited[i])
        {
            dfs(adj,visited, i , flag);
            if(!flag)
            incomplete++;
            else
            complete++;
        }
    }
    ll maximum = incomplete + complete;
    ll minimun = complete + (incomplete ? 1 : 0);
    cout<<minimun<<" "<<maximum;
    return;
}
int main()
{
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
