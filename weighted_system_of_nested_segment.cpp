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

bool cmps(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,m; 
    cin>>n>>m;
    vector<pair<pii,ll>> arr;
    REP(i,0,m)
    {
        ll ele1,ele2;
        cin>>ele1>>ele2;
        arr.pb({{ele1,i+1},ele2});
    }
    sort(arr.begin(),arr.end(),cmps);
    vector<pair<int,int>> idx;
    ll count=0;
    REP(i,0,2*n)
    {
        count+=arr[i].ss;
        idx.pb({arr[i].ff.ff,arr[i].ff.ss});
    }
    sort(idx.begin(),idx.end());
    cout<<count<<"\n";
    REP(i,0,n)
    {
        cout<<idx[i].ss<<" "<<idx[2*n-i-1].ss<<"\n";
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