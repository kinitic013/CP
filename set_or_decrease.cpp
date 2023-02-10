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
    ll n,k;cin>>n>>k;
    vi arr(n);
    vi prefix(n);
    REP(i,0,n)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    REP(i,0,n)
    {
        if(i==0)
        {
            prefix[0]=arr[0];
        }
        else
        prefix[i]=prefix[i-1]+arr[i];
    }
    if(prefix[n-1]<=k)
    {
        cout<<0;
        return;
    }
    if(n==1)
    {
        cout<<abs(arr[0]-k);
        return;
    }
    ll count=LONG_LONG_MAX;
    if(arr[0]*n<=k)
    {
        count=0;
        ll sum=prefix[n-1];
        for(ll i=n-1;i>0;i--)
        {
            sum-=(arr[i]-arr[0]);
            count++;
            if(sum<=k)
            break;
        }
    }
    count=min(abs(prefix[0]-k+(prefix[n-1]-prefix[0])),count);
    ll x=1;
    for(;x<n;x++)
    {
        ll y=(k-(prefix[n-x-1]-prefix[0]))/(x+1);
        ll val=(k-(prefix[n-x-1]-prefix[0]));
        ll rem=(k-prefix[n-x-1]+prefix[0])%(x+1);
        if(rem<0)
        {
            y--;
        }
        count=min(count,abs(prefix[0]-y)+abs(x));
    }
    cout<<count;
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
