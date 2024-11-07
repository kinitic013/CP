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
// dp[i][j] = no. of ways when at jth i.e. top of the tower width of block is i i.e. if i==1 when two blocks of width 1 elseif i ==2 then one block of width 2
ll dp[3][1000001];
void solve()
{
    ll n;cin>>n;
    cout<<(dp[1][n]+dp[2][n])%MOD;
    return;
}
int main()
{
    fast();
    dp[1][1] = 1;
    dp[2][1] = 1;
    for(ll i=2;i<1000001;i++)
    {
        dp[1][i] = (4*dp[1][i-1] + dp[2][i-1])%MOD;
        dp[2][i] = (2*dp[2][i-1] + dp[1][i-1])%MOD;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
