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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll x,k;cin>>k>>x;
    if(x>=k*k)
    {
        cout<<2*k-1;
        return;
    }
    if(x<=(k*(k-1))/2)//first half
    {
        ll l=1;
        ll h=k-1;
        ll ans=h;
        ll mid=(l+h)/2;
        while(l<h)
        {
            
            mid=(l+h)/2;
            ll sum=(mid*(mid+1))/2;
            if(sum>x)
            {
                h=mid;
            }
            else if(sum<x)
            {
                l=mid+1;
            }
            else
            {
                break;
            }
        }
        mid=(l+h)/2;
        ans=mid;
        cout<<ans;
        return;
    }
    else
    {
        ll ans=k-1;
        x-=(k*(k-1))/2;
        ll l=1;
        ll h=k;
        ll mid=(l+h)/2;
        while(l<h)
        {
            mid=(l+h)/2;
            ll sum=(mid*(2*k-mid+1))/2;
            if(sum>x)
            {
                h=mid;
            }
            else if(sum<x)
            {
                l=mid+1;
            }
            else
            {
                break;
            }
        }
       mid=(l+h)/2;
        ans+=mid;
        cout<<ans;
        return;

    }
    return ;
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
