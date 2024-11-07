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
    REP(i,0,n) cin>>arr[i];
    vi brr(n);
    REP(i,0,n) cin>>brr[i];
    ll sum = 0;
    vi pre;
    REP(i,0,n)
    {
        sum += arr[i]*brr[i];
        pre.pb(sum);
    }
    ll result = pre[n-1];
    vvi dp(n,vi(n,0));
    ll diff = 0;
    REP(i,0,n)
    {
        dp[i][i] = arr[i]*brr[i];
    }
    REP(i,0,n-1)
    {
        dp[i][i+1] = arr[i]*brr[i+1] + arr[i+1]*brr[i];
    }
    REP(i,0,n)
    {
        ll x = i;
        ll y = i;
        while(x>=0 && y<n)
        {
            if(dp[x][y] == 0)
            {
                dp[x][y] = dp[x+1][y-1] + arr[x]*brr[y] + arr[y]*brr[x]; 
            }

            ll val = pre[n-1] - pre[y] + dp[x][y];
            if(x!=0)
            val+= pre[x-1];

            result = max<ll>(result,val);

            x--;
            y++;
        }
        x=i;
        y=i+1;
        while(x>=0 && y<n)
        {
            if(dp[x][y] == 0)
            {
                dp[x][y] = dp[x+1][y-1] + arr[x]*brr[y] + arr[y]*brr[x]; 
            }

            ll val = pre[n-1] - pre[y] + dp[x][y];
            if(x!=0)
            val+= pre[x-1];

            result = max<ll>(result,val);

            x--;
            y++;
        }
    }
    cout<<result;
    return ;
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
