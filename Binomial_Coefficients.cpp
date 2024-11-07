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
//modular expo
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

void  solve(vi &arr)
{
    ll a,b;cin>>a>>b;
    ll val=(arr[a]*((power(arr[a-b],MOD-2))))%MOD*(power(arr[b],MOD-2))%MOD;
    cout<<val;
}
int main()
{
    vi arr(1000001,0);
    arr[0]=1;
    REP(i,1,(ll)1e6+1)
    {
        arr[i]=(arr[i-1]*i)%MOD;
    }

    ll t;
    cin>>t;
    while(t--)
    {
        solve(arr);
        cout<<"\n";
    }
    return 0;
}
