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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
ll count=0;
ll max_inrange(vi arr,ll s,ll e)
{
    ll maxi=0;
    REP(i,s,e+1)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    return maxi;
}
bool helper(vi &arr,ll n,ll s,ll e)
{
    if(n==2)//base case
    {
        if(abs(arr[e]-arr[s])>1)
        {
            return false;
        }
        if(arr[s]>arr[e])
        {
            ::count++;
            swap(arr[s],arr[e]);
        }
        return true;
    }
    bool left=helper(arr,n/2,s,e-(n/2));
    bool right=helper(arr,n/2,s+(n/2),e);
    if(!left || !right )
    {
        return false;
    }
    if(arr[s]>arr[e])
    {
        ::count++;
        REP(i,s,s+(n/2))
        {
            swap(arr[i],arr[n/2+i]);
        }
    }
    return true;
}
void  solve()
{
    ll n;cin>>n;
    input
    if(n==1)
    {
        cout<<0;
        return;
    }
    bool val=helper(arr,n,0,n-1);
    REP(i,0,n-1)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<-1;
            ::count=0;
            return;
        }
    }
    if(!val)
    {
        cout<<-1;
    }
    else
    cout<<::count;
    ::count=0;
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
