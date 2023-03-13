#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

bool checker(vi arr,ll x)
{
    ll n=arr.size();
    for(int i=n-1;i>=2;i--)
    {
        if(arr[i]>x)
        {
            ll diff=arr[i]-x;
            ll d=diff/3;
            arr[i]-=(3*d);
            arr[i-1]+=d;
            arr[i-2]+=2*d;
        }
        else
        {
            return false;
        }
    }
    if(arr[0]<x || arr[1]<x)
    return false;
    else
    return true;
}

void  solve()
{
    int n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    ll l=0;ll r=*max_element(arr.begin(),arr.end())+1;
    ll count=40;
    ll ans=l;
    while(count--)
    {
        ll x=(l+r)/2;
        bool check= checker(arr,x);
        if(check)
        {
            l=x;
            ans=max(ans,x);
        }
        else
        {
            r=x+1;
        }
    }
    cout<<ans;
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
