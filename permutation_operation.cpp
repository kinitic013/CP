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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n;cin>>n;
    vi arr;
    vector<pair<ll,pii>> map;
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        arr.pb(ele);
        if(i!=0)
        {
            if(arr[i]<arr[i-1])
            {
                map.pb({arr[i-1]-arr[i],{arr[i],i+1}});
            }
        }
    }
    sort(map.begin(),map.end());
    vi result(n,1);
    ll j=0;ll i=0;
    while(i<n && j<map.size())
    {
        result[i]=map[j].ss.ss;
        map[j].ff-=i+1;
        if(map[j].ff<=0)
        {
            j++;
        }
    }
    REP(i,0,n)
    {
        cout<<result[i]<<" ";
    }
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