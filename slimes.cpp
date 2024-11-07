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
    vi pre;
    ll sum = 0;
    REP(i,0,n)
    {
        cin>>arr[i];
        sum+=arr[i];
        pre.pb(sum);
    }
    vector<vi> dp(n,vi(n,LONG_LONG_MAX));
    REP(i,0,n)
    dp[i][i] = 0;
    ll diff = 1;
    while(diff<=n-1)
    {
        ll i = 0;
        ll j = i + diff;
        while(i<n && j<n)
        {
            ll val = LONG_LONG_MAX;
            REP(k,i,j)
            {
                val = min<ll>( val , dp[i][k] + dp[k+1][j] );
            }
            val += pre[j] ;
            if(i!=0)
            val -= pre[i-1];
            dp[i][j] = min<ll>(dp[i][j] , val );
            i++;
            j++;
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
    // fast();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    {
        solve();
        cout << endl;
    }
    return 0;
}
