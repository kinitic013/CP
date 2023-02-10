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

void  solve()
{
    int n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];

    vi diff;
    diff.pb(0);
    REP(i,1,n-1)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            diff.pb(0);
        }
        else
        {
            diff.pb(max(arr[i-1],arr[i+1])+1-arr[i]);
        }
    }
    diff.pb(0);
    ll result=LONG_LONG_MAX;
    if(n&1)
    {
        result=0;
        for(int i=1;i<n;i+=2)
        {
            result+=diff[i];
        }
    }
    else
    {
        ll curr=0;
        for(int i=1;i<n;i+=2)
        {
            curr+=diff[i];
        }
        result=min(curr,result);

        for(int i=n-3;i>=0;i-=2)
        {
            curr=curr-diff[i]+diff[i+1];
            result=min(curr,result);
        }
    }
    cout<<result;
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
