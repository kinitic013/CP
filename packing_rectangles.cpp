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
bool checker(ll w,ll h,ll n,ll x)
{
    ll val=(x/w)*(x/h);
    if(val>=n)
    {
        return true;
    }
    else
    return false;
}
void  solve()
{
    ll w,h,n;cin>>w>>h>>n;
    ll lo=1;ll hi=1;
    hi=(sqrt(n)+1)*max(h,w);
    while(hi-lo>=1)
    {
        ll x=(lo+hi)/2;
        bool check=checker(w,h,n,x);
        if(check)
        {
            hi=x;
        }
        else
        {
            lo=x+1;
        }
        if(lo==hi)
        {
            break;
        }
    }
    cout<<hi;
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
