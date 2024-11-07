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
void solve()
{
    ll n;cin>>n;
    vi arr(n);
    vi empty,filled;
    REP(i,0,n) 
    {
        cin>>arr[i];
        if(arr[i])
        filled.pb(i);
        else
        empty.pb(i);
    }
    if(filled.empty())
    {
        cout<<0;
        return;
    }
    n = filled.size();
    ll m = empty.size();
    vvi dp(n,vi(m,LONG_LONG_MAX));
    vvi mini(n,vi(m,LONG_LONG_MAX));
    REP(i,0,m-n+1)
    {
        dp[0][i] = abs(empty[i] - filled[0]);
        if(i>=1)
        {
            mini[0][i] = min<ll>(dp[0][i],mini[0][i-1]);
        }
        else
        {
            mini[0][i] = dp[0][i];
        }
    }
    REP(i,1,n)
    {
        REP(j,i,m)
        {
            dp[i][j] = min<ll>(mini[i-1][j-1] + abs(empty[j] - filled[i]) , dp[i][j]);

        }
        REP(j,i,m)
        {
            if(i==j)
            {
                mini[i][j] = dp[i][j];
            }
            else
            {
                mini[i][j] = min<ll>(dp[i][j],mini[i][j-1]);
            }
        }
    }
    cout<<mini[n-1][m-1];
    return;
}
int main()
{
    fast();
    // ll t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}