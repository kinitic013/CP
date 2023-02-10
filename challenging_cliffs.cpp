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
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}

//     REP(i,0,n)
//     {
//         ll ele;
//         cin>>ele;
//         x.pb(ele);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    input
    vi result;
    pii idx;
    sort(arr.begin(),arr.end());
    ll diff=abs(arr[0]-arr[1]); idx.ff=0;idx.ss=1;
    REP(i,0,n-1)
    {
        if((arr[i+1]-arr[i])<diff)
        {
            diff=arr[i+1]-arr[i];
            idx.ff=i;
            idx.ss=i+1;
        }
    }
    result.pb(arr[idx.ff]);
    // result[n-1]=arr[idx.ss];
    ll j=idx.ss+1;
    while(j<n)
    {
        result.pb(arr[j]);
        j++;
    }
    j=0;
    while(j<idx.ff)
    {
        result.pb(arr[j]);
        j++;
    }
    result.pb(arr[idx.ss]);
    REP(i,0,n)
    {
        cout<<result[i]<<" ";
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