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
    ll n,h,l,r;cin>>n>>h>>l>>r;
    vi arr(n);
    REP(i,0,n)
    {
        cin>>arr[i];
    }
    vector<vi> dp(n+1,vi(h+1,-1));
    ll ans = 0;
    dp[0][0] = 0;
    REP(i,0,n)
    {
        REP(j,0,h)
        {
            ll extra = 0;
            if(dp[i][j] != -1)//possible time 
            {
                ll val = (j + arr[i]-1)%h;
                if(val>=l && val<=r)
                extra=1;
                // if arr[i]-1 is added
                dp[i+1][val] = max(dp[i+1][val],dp[i][j]+extra);
                ans = max<ll>(ans,dp[i+1][val]);
                extra=0;

                val = (j+arr[i])%h;
                if(val>=l && val<=r)
                extra=1;
                // if arr[i] is added
                dp[i+1][val] = max(dp[i+1][val],dp[i][j]+extra);
                ans = max<ll>(ans,dp[i+1][val]);
            }
        }
        cout<<"";
    }

    cout<<ans;
    // REP(i,0,h+1)
    // {
    //     if(curr[i]!=-1)
    //     {
    //         cout<<i<<" "<<curr[i]<<endl;
    //         cout.flush();
    //     }
    // }
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
