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
    ll n,k,x;
    cin>>n>>k>>x;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    vector<vi> dp(x+1,vi(n,LONG_LONG_MIN));
    REP(i,0,k)
    dp[1][i] = arr[i];
    // dp[i][j] = max cost when ith choosen element is jth in the array 
    // transition = dp[i][j] = arr[j] + max(dp[i-1][idx] where idx min(0,j-k) t0 j-1)

    REP(i,2,x+1)
    {
        REP(j,i-1,n)
        {
            ll val = LONG_LONG_MIN;
            REP(idx,max<ll>(0,j-k),j)
            {
                val = max<ll>(val,dp[i-1][idx]);
            }
            if(val != LONG_LONG_MIN)
            val += arr[j];

            dp[i][j] = val;
        }
    }
    ll ans = LONG_LONG_MIN;
    REP(i,n-k,n)
    {
        ans = max<ll>(ans , dp[x][i]);
    }
    if(ans == LONG_LONG_MIN)
    cout<<-1;
    else
    cout<<ans;
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
