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
void solve(vi& p)
{
    ll n,m;cin>>n>>m;
    vpii segment(n);
    map<ll,ll> mapping;
    REP(i,0,n)
    {
        cin>>segment[i].ff>>segment[i].ss;
        segment[i].ff--;
        segment[i].ss--;
        mapping[segment[i].ff] = segment[i].ff;
        mapping[segment[i].ss] = segment[i].ss;
    }
    mapping[0] = 0;
    mapping[m-1] = m-1;
    auto it = mapping.begin();
    ll idx = 0;
    pii end ;
    while(it!=mapping.end())
    {
        it->ss = idx;
        idx++;
        it++;
        if(it == mapping.end())
        {
            it--;
            end.ff = it->first;
            end.ss = it->second;
            break;
        }
    }
    ll last = end.ss;
    REP(i,0,n)
    {
        segment[i].ff = mapping[segment[i].ff];
        segment[i].ss = mapping[segment[i].ss];
    }
    // crray compression done;
    ll ans = 0;
    vi arr(last+1000,0);
    // minimizing 0th idx
    REP(i,0,n)
    {
        if(segment[i].ff == 0)
        continue;

        arr[segment[i].ff]++;
        arr[segment[i].ss +1]--;
    }
    ans = max(ans , arr[0]);
    REP(i,1,arr.size())
    {
        ans = max(ans , arr[i]);
        arr[i] = arr[i-1] + arr[i];
        ans = max(ans , arr[i]);
    }
    // minimizing last idx
    arr = vi(last+1000,0);
    REP(i,0,n)
    {
        if(segment[i].ss == last)
        continue;

        arr[segment[i].ff]++;
        arr[segment[i].ss +1]--;
    }
    ans = max(ans , arr[0]);
    REP(i,1,arr.size())
    {
        ans = max(ans , arr[i]);
        arr[i] = arr[i-1] + arr[i];
        ans = max(ans , arr[i]);
    }
    cout<<ans;
    return;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vi p;
    ll ele = 1;
    REP(i,0,32)
    {
        p.pb(ele);
        ele*=2;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        solve(p);
        cout << endl;
    }
    return 0;
}