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
//         ll arr;
//         cin>>arr;
//         x.pb(arr);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,h;
    cin>>n>>h;
    input
    ll s=1,e=min((ll)1e18,h);

    while(s<e)
    {
        ll value=0;
        ll k=(s+e)/2;
        REP(i,0,n-1)
        {
            value+=min(k,arr[i+1]-arr[i]);
        }
        value+=k;
        if(value>=h)
        {
            e=k;
        }
        else
        {
            s=k+1;
        }
    }
    cout<<e;
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