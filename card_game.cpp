#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
ll fact(ll n);
 
ll nCr(ll n, ll r)
{
    if(n==0)
    {
        return 0;
    }
    return fact(n) / (fact(r) * fact(n - r))%998244353;
}
vector<vector<ll>> dp(61,vector<ll>(61,0));
// Returns factorial of n
ll fact(ll n)
{
      if(n==0)
      return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res =( res * i);
    return res%998244353;
}
void helper(ll &alex,ll& boris, ll n,ll i)
{
    if(n==0)
    {
        return ;
    }
    if(i&1)
    {
        alex +=dp[n-1][n/2];
        boris += dp[n-2][n/2];
    }
    else
    {
        boris +=dp[n-1][n/2];
        alex += dp[n-2][n/2];
    }
    helper(alex,boris,n-2,i+1);
}
void  solve()
{
    ll n;
    cin>>n;
    ll alex=0,boris=0;
    ll count=0;
    helper(alex,boris,n,1);
    ll draw=1;
    cout<<alex%998244353<<" "<<boris%998244353<<" "<<draw;
    return ;
}
int main()
{
    ll t;
    cin>>t;
    REP(n,1,61)
    {
        REP(r,0,n+1)
        {
            if(r==0)
            {
                dp[n][r]=1;
                continue;
            }
            if(r==1)
            {
                dp[n][r]=n;
                continue;
            }
            if(n==r)
            {
                dp[n][r]=1;
                continue;
            }
            dp[n][r]=(dp[n-1][r]+dp[n-1][r-1]);
        }
    }
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}