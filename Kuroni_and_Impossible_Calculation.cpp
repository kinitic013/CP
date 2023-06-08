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
void  solve()
{
    ll n,m;cin>>n>>m;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll prod=1;
    if(n<=m)
    {
        REP(i,0,n)
        {
            REP(j,i+1,n)
            {
                prod=(prod*(arr[j]-arr[i])%m)%m;
            }
        }
        cout<<prod;return;
    }
    else
    {
        // since n>m  if there exist n distinct integer then ai%m is going to repeat that means difference of those two elements is going to be zero 
        // and i could not solve that problem on my own but learned this way to think and solve (sort of pigeonhole princeple ) 
        cout<<0;
        return;
    }
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
