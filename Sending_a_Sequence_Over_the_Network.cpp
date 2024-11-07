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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    vi arr(n+1);
    REP(i,1,n+1)
    cin>>arr[i];
    if(n==1)
    {
        cout<<"NO";
        return;
    }
    vi dp(n+1,0);
    dp[0]=1;
    REP(i,1,n+1)
    {
        {
            if(i+arr[i]<=n)
            {
                if(dp[i-1]==1)
                dp[i+arr[i]]=1;
            }
            if(i-arr[i]-1>=0)
            {
                if(dp[i-arr[i]-1]==1)
                dp[i]=1;
            }
        }   
    }
    if(dp[n]==1)
    {
        cout<<"YES";
        return;
    }
    else 
    {
        cout<<"NO";
        return;
    }
    return;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
