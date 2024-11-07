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
    ll n, m;
    cin >> n >> m;
    vector<vector<vi>> dp(m, vector<vi>(n, vi(n, 0)));
    REP(i, 0, n)
    {
        REP(j, i, n)
        {
            dp[0][i][j] = 1;
        }
    }
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            ll val = dp[0][i][j];
            if (i - 1 >= 0)
                val = (val + dp[0][i - 1][j]) % MOD;
            if (j - 1 >= 0)
                val = (val + dp[0][i][j - 1]) % MOD;
            if (i - 1 >= 0 && j - 1 >= 0)
                val = (val - dp[0][i - 1][j - 1] + MOD) % MOD;

            dp[0][i][j] = val;
        }
    }
    REP(i, 1, m)
    {
        REP(j, 0, n)
        {
            REP(k, j, n)
            {
                dp[i][j][k] = dp[i - 1][k][k];
                if (j - 1 >= 0)
                {
                    dp[i][j][k] = (dp[i][j][k] - dp[i - 1][j - 1][k]) % MOD;
                }
            }
        }
        REP(k, 0, n)
        {
            REP(j, 0, n)
            {
                ll val = dp[i][k][j];
                if (k - 1 >= 0)
                    val = (val + dp[i][k - 1][j]) % MOD;
                if (j - 1 >= 0)
                    val = (val + dp[i][k][j - 1]) % MOD;
                if (k - 1 >= 0 && j - 1 >= 0)
                    val = (val - dp[i][k - 1][j - 1] + MOD) % MOD;

                dp[i][k][j] = val;
            }
        }
    }
    cout << dp[m - 1][n - 1][n - 1];
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
