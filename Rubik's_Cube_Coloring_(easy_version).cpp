#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll , null_type,less<ll >, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(ll  i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
ll Fast_Expo(ll a,ll n)
{
    ll last_bit=n&1;
    ll ans=1;
    while(n>0)
    {
        last_bit=n&1;
        if(last_bit)
        {
            ans+=a;
        }
        a=(a*a)%(ll)(1e9+7);
        n=n>>1;
    }
    return ans%(ll)(1e9+7);
}
void  solve()
{
    ll k;cin>>k;
    ll pow=Fast_Expo(2,(k+1))-4;
    ll val=(6*Fast_Expo(2,pow))%(ll)(1e9+7);
    cout<<val;
}
int  main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
