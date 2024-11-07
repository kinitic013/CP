#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll int64_t
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
bool isKthBitSet(ll n, ll k)
{
    if (n & (1 << k))
        return 1;
    else
        return 0;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vi arr(n);
    vi temp;
    REP(i, 0, n)
    cin >> arr[i];
    temp = arr;

    REP(x, 0, q)
    {
        ll k;
        cin >> k;
        arr = temp;
        for (ll i = 62; i >= 0; i--)
        {
            ll count = 0;
            bool flag = 0;
            ll mask = (1ll << (i + 1)) - 1;
            ll set = (1ll << (i));
            REP(j, 0, n)
            {
                if (count > k)
                {
                    flag = 1;
                    break;
                }
                ll remain = arr[j] & mask;
                if (remain > set)
                {
                    continue;
                }
                {
                    ll need = set - remain;
                    count = count + need;
                    if (count < 0 || count > k)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
            {
                continue;
            }
            if (count <= k)
            {
                k -= count;
                REP(j, 0, n)
                {
                    ll remain = arr[j] & mask;
                    if (remain > set)
                    {
                        continue;
                    }
                    ll need = set - remain;
                    arr[j] += need;
                }
            }
        }
        ll ans = arr[0];
        REP(i, 0, n)
        {
            ans = ans & arr[i];
        }
        cout << ans << endl;
    }
    return;
}
int main()
{
    fast();
    {
        solve();
        cout << endl;
    }
    return 0;
}
