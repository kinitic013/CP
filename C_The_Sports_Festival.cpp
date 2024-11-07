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
void solve()
{
    ll n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    sort(all(arr));

    vvi dp(n,vi(n,0));
    ll diff = 1;
    REP(i,0,n)
    {
        ll x = 0;
        ll y = x + diff;
        while(x<n && y<n)
        {
            dp[x][y] = arr[y]-arr[x] + min<ll>(dp[x+1][y],dp[x][y-1]);
            // main logic : d[lastidx] = max(arr) - min(arr) 
            x++;
            y++;
        }
        diff++;
    }
    cout<<dp[0][n-1];
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
