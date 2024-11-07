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
    REP(i,1,n+1) cin>>arr[i];
    vi dp(n+1,0);
    map<ll,ll> m;
    
    REP(i,1,n+1)
    {
        
        auto add=m.find(arr[i]);
        if(add==m.end())//not found
        {
            dp[i]=dp[i-1];
            m[arr[i]]=1+dp[i-1]-i;
        }
        else// found
        {
            dp[i]=max(dp[i-1],i+m[arr[i]]);
            m[arr[i]]=max(m[arr[i]],1+dp[i-1]-i);
        }
    }
    cout<<dp[n];

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
