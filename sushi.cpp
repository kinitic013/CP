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
double helper(vector<vector<vector<double>>> &dp, ll z, ll o, ll t, ll th)
{
    if (z == 3 && o == 2 && t == 1 && th == 1)
    {
        cout << "";
    }
    if (o < 0 || t < 0 || th < 0)
        return (double)0.0;
    if (dp[o][t][th] != -1.0)
        return dp[o][t][th];

    ll total = z + o + t + th;
    ll base = o + t + th;
    if (base == 0)
    {
        return dp[0][0][0];
    }
    double val1, val2, val3;
    if (o > 0)
    {
        if (dp[o - 1][t][th] == -1.0)
        {
            val1 = helper(dp, z + 1, o - 1, t, th);
        }
        else
        {
            val1 = dp[o - 1][t][th];
        }
    }
    if (t > 0)
    {
        if (dp[o + 1][t - 1][th] == -1.0)
        {
            val1 = helper(dp, z, o + 1, t - 1, th);
        }
        else
        {
            val1 = dp[o + 1][t - 1][th];
        }
    }
    if (th > 0)
    {
        if (dp[o][t + 1][th - 1] == -1.0)
        {
            val1 = helper(dp, z, o, t + 1, th - 1);
        }
        else
        {
            val1 = dp[o][t + 1][th - 1];
        }
    }
    val1 = ((double)o / base) * (val1);
    val2 = ((double)t / base) * (val2);
    val3 = ((double)th / base) * (val3);
    double val = val1 + val2 + val3 + ((double)total / base);
    dp[o][t][th] = val;
    return dp[o][t][th];
}
void solve()
{
    ll n;
    cin >> n;
    vi arr(n);
    ll sum = 0;
    ll z = 0;
    ll o = 0;
    ll t = 0;
    ll th = 0;
    REP(i, 0, n)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            z++;
        if (arr[i] == 1)
            o++;
        if (arr[i] == 2)
            t++;
        if (arr[i] == 3)
            th++;

        sum += arr[i];
    }
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1.0)));
    dp[0][0][0] = 0;
    // one = 0 , two = 0 , three = 0
    ll total = z + o + t + th;
    ll base = o + t + th;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n-i; j++)
        {
            for (int k = 0; k <= n-i-j; k++)
            {
                double val1 = 0, val2 = 0, val3 = 0;
                if (i == 0 && j == 0 && k == 0)
                    continue;

                if (k > 0)
                    val1 = dp[k - 1][j][i];
                if (j > 0)
                    val2 = dp[k + 1][j - 1][i];
                if (i > 0)
                    val3 = dp[k][j + 1][i - 1];

                ll base = i + j + k;

                val1 = ((double)k / base) * (val1);
                val2 = ((double)j / base) * (val2);
                val3 = ((double)i / base) * (val3);

                double val = val1 + val2 + val3 + ((double)total /base);
                dp[k][j][i] = val;
            }
        }
    }
    cout<<fixed;
    cout<<setprecision(10);
    cout << dp[o][t][th];
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
