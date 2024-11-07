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
    ll a,b;cin>>a>>b;
    int n;string arr;cin>>arr;n=arr.size();
    ll val=a;
    ll flag=0;
    ll star=0;
    ll i=0;bool onefound=0;
    REP(i,0,n)
    {
        if(arr[i]=='1')
        {
            onefound=1;
            break;
        }
    }
    if(!onefound)
    {
        cout<<0;
        return;
    }
    for(;i<n-1;i++)
    {
        if(arr[i]=='1' && arr[i+1]=='0')
        {
            i++;
            break;
        }
    }
    ll count=0;
    for(;i<n-1;i++)
    {
        if(arr[i]=='0')
        {
            count++;
        }
        if(arr[i]=='0' && arr[i+1]=='1')
        {
            val+=min(count*b,a);
            count=0;
        }
    }
    cout<<val;
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
