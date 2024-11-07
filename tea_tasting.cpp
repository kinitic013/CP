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
    ll n;cin>>n;
    vi a(n),b(n);
    REP(i,0,n) cin>>a[i];
    vi pre;
    REP(i,0,n)
    {
        cin>>b[i];
        if(i!=0)
        {
            pre.pb(pre[i-1]+b[i]);
        }
        else
        {
            pre.pb(b[0]);
        }
    }
    vi ans(n,0);
    vi arr(n+1,0);
    ll sum=0;
    REP(i,0,n)
    {
        if(i!=0)
        {
            sum=pre[i-1];
        }
        ll val=a[i]+sum;
        auto add=upper_bound(pre.begin(),pre.end(),a[i]+sum);
        ll idx=add-pre.begin();

        if(add!=pre.begin() && idx>=0 && idx<n && idx>i)
        {
            ans[idx]+=(a[i]-pre[idx-1]+sum);
            add--;
        }
        else if(idx>=0 && idx<n)
        {
            ans[idx]+=a[i];
            continue;
        }
        arr[i]++;
        arr[idx]--;
    }
    vi diff(n,0);
    REP(i,0,n)
    {
        if(i==0)
        {
            diff[i]=arr[i];
        }
        else
        {
            diff[i]=arr[i]+diff[i-1];
        }
    }
    ll count=0;
    REP(i,0,n)
    {
        ans[i]+=diff[i]*b[i];
    }
    REP(i,0,n)
    {
        cout<<ans[i]<<' ';
    }
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
