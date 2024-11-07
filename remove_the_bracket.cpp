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
    long long l = 0, r = 5000000001;
    while (r - l > 1)
    {
        long long mid = (l + r) / 2;
        if (1ll * mid * mid <= a)
            l = mid;
        else
            r = mid;
    }
    return l;
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
void solve()
{
    ll n, s;
    cin >> n >> s;
    vi arr(n);
    REP(i, 0, n)
        cin >> arr[i];
    vector<pii> limit(n, {0, 0});
    REP(i,0,n)
    {
        pii range;
        if (2 * s <= arr[i])
        {
            range.ff = s;
            range.ss = arr[i] - s;
        }
        else
        {
            range.ff = max<ll>(arr[i] - s, 0);
            range.ss = min<ll>(s, arr[i]);
        }
        limit[i] =  range ;
    }
    limit[0]={arr[0],arr[0]};
    limit[n-1]={arr[n-1],arr[n-1]};
    vector<vector<ll>> dp(n,{0,0});
    // F = a1x2 + y2x3 + y3x4 + ... + yn-2xn + yn-1an
    // dp[i][0] = minimum value of F till y(i-1)x(i)th term by placing xi as maximum
    // dp[i][1] = minimum value of F till y(i-1)x(i)th term by placing xi as minimum
    REP(i,1,n)
    {
        ll val1 = (dp[i-1][0] + limit[i-1].ff * limit[i].ss);
        ll val2 = (dp[i-1][1] + limit[i-1].ss * limit[i].ss);
        ll val3 = (dp[i-1][0] + limit[i-1].ff * limit[i].ff);
        ll val4 = (dp[i-1][1] + limit[i-1].ss * limit[i].ff);

        dp[i][0] = min<ll>(val1,val2);
        dp[i][1] = min<ll>(val3,val4);
    }
    cout<<min<ll>(dp[n-1][0],dp[n-1][1]);
    return ;
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
