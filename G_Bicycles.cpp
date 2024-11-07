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
class state
{
public:
    ll node,cycle;
    state(ll n,ll c){
        this->cycle = c;
        this->node = n;
    }
};
struct CustomComparator {
    bool operator()(pair<ll, state>& a, pair<ll, state>& b){
        // Implement your comparison logic here
        // For example, compare based on the first element of the pair:
        return a.ff > b.ff;
    }
};
// ll dist[1001][1001];
void dijkstra(vector<vpii>& adj, vi& slowness, ll n , ll m , ll c_max)
{
    vvi dist(n+1,vi(c_max+1,LONG_LONG_MAX));
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j = 1 ;j<=c_max;j++)
    //     dist[i][j] = INT_MAX;
    // }
    priority_queue<pair<ll,state>,vector<pair<ll,state>>,CustomComparator> q;
    vector<vb> visited(n+1,vb(c_max+1,false));
    q.push({0LL,state(1LL,slowness[1LL])});
    dist[1LL][slowness[1]] = 0;
    while(!q.empty())
    {
        pair<ll,state> t = q.top();q.pop();
        ll cost = t.ff;
        state st = t.ss;

        visited[st.node][st.cycle] = 1;

        if(st.node == n)
        {
            continue;
        }
        // debug(cost,st.node,st.cycle);
        for(auto x : adj[st.node])
        {
            if(visited[x.ff][(min<ll>(st.cycle,slowness[st.node]))] != 1)
            {
                ll extra =(x.ss*(min<ll>(st.cycle,slowness[st.node])));
                if(cost + extra < dist[x.ff][min<ll>(st.cycle,slowness[st.node])] )
                {
                    dist[x.ff][min<ll>(st.cycle,slowness[st.node])] = cost + extra;
                    q.push({cost+extra,state(x.ff,min<ll>(st.cycle,slowness[x.ff]))});
                    // debug(cost+extra,state(x.ff,min<ll>(st.cycle,slowness[x.ff])));
                    // cout<<endl;
                }
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    for(int i=1;i<=c_max;i++)
    {
        ans = min(ans,dist[n][i]);
    }
    cout<<ans;
    return;
}
void solve(ll t)
{
    ll n,m;cin>>n>>m;
    vector<vpii> adj(n+1);
    REP(i,0,m)
    {
        ll u,v,w;cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vi cost(n+1,0);
    REP(i,1,n+1)
    cin>>cost[i];

    dijkstra(adj,cost,n,m,*max_element(all(cost)));
}

int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    REP(T,1,t+1)
    {
        solve(T);
        cout << endl;
    }
    return 0;
}