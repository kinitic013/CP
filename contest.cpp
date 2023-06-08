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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve(vi &power)
{
    ll n,k;cin>>n>>k;
    ll bits=log2(n)+1;
    if(bits<=k)
    {
        cout<<n+1;
        return;
    }
    else
    {
        ll val=min((ll)30,k);
        cout<<power[val];
    }
    return;
}
int main()
{
    ll t;
    cin>>t;
    vi power;
    power.pb(1);
    REP(i,1,31)
    {
        power.pb(power[i-1]*2);
    }
    while(t--)
    {
        solve(power);
        cout<<"\n";
    }
    return 0;
}
