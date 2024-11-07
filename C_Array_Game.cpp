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
    ll n, k;
    cin >> n >> k;
    vi arr(n);
    REP(i, 0, n)
        cin >> arr[i];
    sort(all(arr));
    if (k >= 3)
    {
        cout << 0;
        return;
    }
    vi all_diff;
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            if (i == j)
                continue;

            all_diff.pb(abs(arr[j] - arr[i]));
        }
    }
    sort(all(all_diff));
    if (k == 2)
    {
        ll ans = arr[0];
        REP(i, 0, all_diff.size())
        {
            auto add = lower_bound(all(arr), all_diff[i]);
            ll val1 = LONG_LONG_MAX, val2 = LONG_LONG_MAX;
            if (add == arr.end())
            {
                add--;
            }
            val2 = abs(*add - all_diff[i]);
            if (add != arr.begin())
            {
                add--;
                val1 = abs(*add - all_diff[i]);
            }
            ans = min<ll>(ans, min(val1, val2));
        }
        ans = min<ll>(ans, all_diff[0]);
        cout << ans;
        return;
    }
    else if (k == 1)
    {
        cout<<min<ll>(arr[0],all_diff[0]);
        return;
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
