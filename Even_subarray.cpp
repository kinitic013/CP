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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    vi arr(n); REP(i,0,n) cin>>arr[i];
    ll count=0;
    vi sqr;
    for(int i=0;i*i<=262144;i++)
    {
        sqr.push_back(i*i);
    }
    vi m(2*n,0);
    ll xr=0;
    REP(i,0,n)
    {
        xr=xr^arr[i];
        REP(j,0,sqr.size())
        {
            ll val=xr^sqr[j];
            if(xr==sqr[j])
            count++;
            if(val>=2*n)
            continue;
            else
            count+=m[val];
        }
        m[xr]++;
    }
    ll result=((n*(n+1))/2)-count;
    cout<<result;
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
