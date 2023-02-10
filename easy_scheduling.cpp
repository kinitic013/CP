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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve(vi dp)
{
    ll n,p;
    cin>>n>>p;
    ll count=0;ll rem=0;
    REP(i,0,n)
    {
        if(dp[i]/p==0)
        {
            count++;
        }
        else
        count+=(dp[i]/p);
        if(dp[i]%p!=0 && dp[i]/p!=0)
        {
            rem+=dp[i]%p;
        }
    }
    count+=ceil(rem/p);
    ll val=n&(n-1);
    if(val!=0 && rem!=0)
    {
        count++;
    }
    cout<<count;
    return ;
}
int main()
{
    ll t;
    cin>>t;
    vi dp;
    REP(i,0,51)
    {
        if(i==0)
        {
            dp.pb(1);
            continue;
        }
        ll ele=dp[i-1]*2;
        dp.push_back(ele);
    }
    while(t--)
    {
        solve(dp);
        cout<<"\n";
    }
    return 0;
}