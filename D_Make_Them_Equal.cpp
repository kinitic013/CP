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
bool cmps(vi& a, vi& b)
{
    if(a[2]!=b[2])
    return a[2]<b[2];
    else
    return a[1]<b[1];
}
vi dijkstra(vector<vi> & adj,ll source)
{
    ll n=adj.size();
    vector<bool> visited(n+1,false);

    vi distance(n+1,INT_MAX);
    distance[source]=0;
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0,source});
    while(!q.empty())
    {
        ll node=q.top().ss;
        ll dist=q.top().ff;
        if(visited[node])
        {
            q.pop();
            continue;
        }
        visited[node]=1;
        q.pop();
        REP(i,0,adj[node].size())
        {
            ll next=adj[node][i];
            ll len=1;
 
            distance[next]=min(distance[next],distance[node]+len);  
 
            if(!visited[next])
            q.push({(distance[next]),next});
        }
    }   
    return distance;
}
void  solve(vi& move)
{
    ll n,k;cin>>n>>k;
    vector<vi> arr(n,vi(3,0)); // 0 , 1, 2 
                               // b , c , cost
    ll total_coins = 0, total_cost = 0;
    REP(i,0,n)
    {
        cin>>arr[i][0];
    }
    REP(i,0,n)
    {
        cin>>arr[i][1];
        total_coins+=arr[i][1];
    }
    REP(i,0,n)
    {
        if(arr[i][0]<move.size())
        arr[i][2] = move[arr[i][0]];

        total_cost+=arr[i][2];
    }
    sort(all(arr),cmps);
    // if(k == 6180)
    // cout<<"Passed\n";
    if(k>=total_cost)
    {
        cout<<total_coins;
        return;
    }
    // if(n == 1000 && k == 6180)
    // {
    //     cout<<total_coins<<" "<<total_cost<<endl;
    //     cout<<k<<" "<<12*k<<" "<<endl;
    //     return;
    // }
    vi dp(min<ll>(12*n , k) + 1,0);
    ll ans = 0;
    REP(i,0,n)
    {
        for(ll j=k-arr[i][2];j>=0;j--)
        {
            dp[j + arr[i][2]] = max<ll>(dp[j] + arr[i][1] , dp[j + arr[i][2]]);
            ans = max<ll>(ans,dp[j + arr[i][2]]);
        }
    }
    cout<<ans;
    return;
}
int main()
{
    vector<vi> adj(1002);
    REP(i,1,1002)
    {
        //create edges
        set<ll> weights;
        REP(j,1,i+1)
        {
            ll val = i/j;
            weights.insert(val);
        }
        auto it = weights.begin();
        while(it!=weights.end())
        {
            if(i+(*it)<=1001)
            {
                adj[i].pb(i+(*it));
            }
            it++;
        }
    }
    vi moves = dijkstra(adj,1);
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        solve(moves);
        cout << endl;
    }
    return 0;
}