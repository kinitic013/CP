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
    ll n,k,z;cin>>n>>k>>z;
    vi a(n);
    REP(i,0,n)
    cin>>a[i];

    n = k+1;
    vi arr(n+1);
    vi prefix;
    ll sum = 0;
    prefix.pb(sum);
    REP(i,1,n+1)
    {
        arr[i] = a[i-1];
        sum+=arr[i];
        prefix.pb(sum);
    }
    vector<vi> dp(z+1,vi(n+1,0));
    REP(i,0,z+1)
    {
        dp[i][1] = sum;
    }
    ll ans = sum;
    REP(i,2,n+1)
    {
        ll limit = (n - i)/2;
        ll extra = (n - i)%2;

        REP(j,0,z+1)
        {
            ll val ;
            if(j<=limit)
            {
                val = prefix[n-(2*j)] + j*(arr[i]+arr[i-1]);
            }
            else
            {
                if(j-1==limit && extra == 1)
                {
                    val = prefix[i] + limit*(arr[i]+arr[i-1]) + max<ll>(arr[i-1],arr[i+1]);
                }
                else
                {
                    dp[j][i] =  dp[j-1][i];
                }
            }
            dp[j][i] = val;
            ans = max<ll>(ans,val);
        }
    }
    cout<<ans;
    return ;
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
