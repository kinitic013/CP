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

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n, p;
    cin >> n >> p;
    vi leg;
    vi sum;
    vi dp(n);
    vi arr;
    ll sumi = 0;
    REP(i, 0, n)
    {
        ll ele;
        cin >> ele;
        arr.pb(ele);
        sumi += ele;
        sum.pb(sumi);
    }
    REP(i,0,p)
    {
        ll ele;
        cin>>ele;
        leg.pb(ele);
        
    }
    ll maxi=arr[0];
    ll j=n-1;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
        dp[i]=maxi;
    }
    REP(i,0,p)
    {
        auto it=upper_bound(dp.begin(),dp.end(),leg[i]);
        if(it==dp.end())
        {
            cout<<sum[n-1]<<" ";
            continue;
        }
        if(*it>leg[i] && it!=dp.begin())
        {
            it--;
        }
        if(it==dp.begin() && *it>leg[i])
        {
            cout<<0<<" ";
            continue;
        }
        ll pos=it-dp.begin();
        cout<<sum[pos]<<" ";
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