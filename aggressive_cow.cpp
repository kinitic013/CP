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
ll mini=LONG_LONG_MAX;
bool checker(vi arr,ll c,ll mid)
{
    ll n=arr.size();
    ll last=arr[0];
    mini=LONG_LONG_MAX;
    c--;
    REP(i,1,n)
    {
        if(arr[i]-last>=mid)
        {
            c--;
            mini=min(arr[i]-last,mini);
            last=arr[i];
        }
    }
    if(c>0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void  solve()
{
    ll n,c;cin>>n>>c;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll l=arr[1]-arr[0];
    ll r=arr[n-1]-arr[0]+1;
    ll ans=l;
    ll count=600;
    while(count--)
    {
        ll mid=(r+l)/2;
        if(checker(arr,c,mid))
        {
            if(mini!=LONG_LONG_MAX)
            {
                ans=max(mini,ans);
            }
            l=mid;
        }
        else
        {
            r=mid-1;
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
