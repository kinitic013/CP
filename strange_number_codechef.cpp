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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

ll power(ll x, ll y, ll p=(ll)(1e9+7))
{
    ll res = 1;  
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
vi primeFactors(ll n)
{
    vi ans;
    // Prll the number of 2s that divide n
    while (n % 2 == 0)
    {
        n = n/2;ans.pb(2);
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            {
                ans.pb(i);
            }
            n = n/i;
        }
    }
    if (n > 2)
    ans.pb(n);

    return ans;
}

void  solve()
{
    ll x,r;cin>>x>>r;
    vi arr=primeFactors(x);
    if(arr.size()<r)
    {
        cout<<0;
    }
    else
    cout<<1;
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
