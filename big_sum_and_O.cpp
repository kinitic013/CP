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
vi fact(100001,0);
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
ll npr(ll n, ll r)
{
    return n*(n-1)%MOD;
}

void  solve()
{
    ll n,k;
    cin>>n>>k;
    ll val=(ll)(pow(2,k-1)-1)*(n*(n-1)%MOD);
    val=(val+n)%MOD; 
    cout<<val;
    return;  
}
int main()
{
    ll t;
    fact[0]=1;
    REP(i,1,100001)
    {
        fact[i]=(i*fact[i-1])%MOD;
    }
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}