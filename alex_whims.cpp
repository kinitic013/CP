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
#define vpii vector<pii>
#define pairMinHeap priority_queue<pii , vpii, greater<pii> > 
#define all(x) (x).begin(), (x).end()
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define revREP(i,a,b) for (ll i = a ; i>b ; i--)
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
// void DFS(vector<vector<ll>>& adj,vector<bool>& visited , ll node)
// {
//     if(visited[node])
//     return;
//     visited[node] = 1;

//     for(auto x : adj[node])
//     {
//         if(!visited[x])
//         {
//             cout<<node<<" "<<x<<endl;
//             DFS(adj,visited,x);
//         }
//     }
//     return;
// }
void solve()
{
    ll n,q;cin>>n>>q;
    vvi arr(n+1);
    REP(i,1,n)
    {
        arr[i].pb(i+1);
    }
    vi d(q);
    ll curr = n-1;
    ll idx = n-1;
    vector<pair<ll,pii>> res;
    REP(i,0,n-1)
    {
        cout<<i+1<<" "<<i+2<<endl;
    }
    REP(i,0,q)
    {
        cin>>d[i];
        if(d[i] == curr)
        {
            res.pb({-1,{-1,-1}});
        }
        else
        {
            ll prevIdx ;
            auto it = arr[idx].begin();
            while(it!=arr[idx].end())
            {
                if(*it == n)
                {
                    arr[idx].erase(it);
                    break;
                }
                it++;
            }
            prevIdx = idx;
            idx = d[i];
            arr[idx].pb(n);
            curr = d[i];
            res.pb({n,{prevIdx,idx}});
        }
    }
    // vb visited(n+1,false);
    // DFS(arr,visited,1);
    for(auto x : res)
    {
        cout<<x.ff<<" "<<x.ss.ff<<" "<<x.ss.ss<<endl;
    }

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