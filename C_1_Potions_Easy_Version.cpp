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
    ll n;
    cin >> n;
    vi arr(n);
    REP(i, 0, n)
        cin >> arr[i];
    vvi dp(n + 1, vi(n + 1, LONG_LONG_MIN));
    REP(i,0,n+1)
    {
        dp[i][0] = 0;
    }
    ll ans = 0;
    REP(i, 1, n + 1)
    {
        if (dp[i-1][i-1] == LONG_LONG_MIN)
        {
            dp[i][i] = LONG_LONG_MIN;
        }
        else
        dp[i][i] = dp[i - 1][i - 1] + arr[i - 1];
        if (dp[i][i] >= 0)
        {
            ans = max<ll>(ans, i);
        }
        else
        {
            dp[i][i] = LONG_LONG_MIN;
        }
    }

    REP(i, 1, n + 1)
    {
        REP(j, 1, i)
        {
            if (i == j)
                continue;

            if (dp[i - 1][j] == LONG_LONG_MIN && dp[i - 1][j - 1] == LONG_LONG_MIN)
            {
                dp[i][j] = LONG_LONG_MIN;
            }
            else
            dp[i][j] = max<ll>(dp[i - 1][j], (dp[i - 1][j - 1] == LONG_LONG_MIN) ? dp[i - 1][j] : dp[i - 1][j - 1] + arr[i - 1]);
            if (dp[i][j] >= 0)
            {
                ans = max<ll>(ans, j);
            }
            if (dp[i][j] < 0)
            {
                dp[i][j] = LONG_LONG_MIN;
            }
        }
    }
    cout << ans;
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
