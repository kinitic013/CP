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
void solve(vvi& dp)
{
    ll n,m;cin>>n>>m;
    ll count = 0;
    do
    {
        ll next = n%10; n/=10;
        ll value = dp[next][m];
        count = (count + value)%MOD;
    }while(n);
    cout<<count;
}
int main()
{
    fast();
    ll t;
    cin >> t;
    vvi dp(10,vi(2e5+1,1));
    //dp[i][j] : lenght of 'i' string after j operations  
    REP(j,1,2e5+1)
    {
        REP(i,0,10)
        {
            if(i!=9)
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = (dp[0][j-1] + dp[1][j-1])%MOD;
            }
        }
    }

    while (t--)
    {
        solve(dp);
        cout << endl;
    }
    return 0;
}
