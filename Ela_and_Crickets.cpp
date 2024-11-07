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
#define mod (ll)998244353
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll size;cin>>size;
    ll x,y,m,n,p,q;cin>>x>>y>>m>>n>>p>>q;
    ll a,b;cin>>a>>b;
    ll cx,cy;
    cx=x,cy=y;
    if(cx!=m)
    {
        cx=p;
    }
    if(cy!=n)
    {
        cy=q;
    }
    if(cx==cy && cx==1)
    {
        if(a==1 || b==1)
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }
    else if(cx==1 && cy==size)
    {
        if(a==1 || b==size)
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }
    else if(cx==size && cy==1)
    {
        if(a==size || b==1)
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }
    else if(cx==size && cy==size)
    {
        if(a==size || b==size)
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }

    if((cx&1 && a&1) || (cy&1 && b&1) || (cx%2==0 && a%2==0) || (cy%2==0 && b%2==0))
    {
        cout<<"YES";
    }
    else 
    cout<<"NO";
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

