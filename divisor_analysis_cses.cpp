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
int power(ll x, ll y, ll p=(ll)(1e9+7))
{
    int res = 1;  
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void  solve()
{
    ll n;cin>>n;
    ll root=1;
    vector<pii> arr;
    bool odd=0;
    ll x=1;
    vi val;
    REP(I,0,n)
    {
        ll ele1,ele2;
        cin>>ele1>>ele2;
        arr.pb({ele1,ele2});
        x=(x*power(ele1,ele2))%MOD;
        if(ele2&1)
        odd=1;
        // if(sq)
        // {
        //     root=(root*(power(ele1,ele2/2)))%MOD;
        // }
    }
    ll num=1;ll sum=1;
    REP(i,0,n)
    {
        num=(num*(arr[i].ss+1)%MOD)%MOD;
        sum=(sum*(((power(arr[i].ff,arr[i].ss+1)-1)%MOD)*(power(arr[i].ff-1,MOD-2))))%MOD;
    }
    ll prod=1;
    
    cout<<num<<" "<<sum<<" "<<prod;
    return;
}
int main()
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
