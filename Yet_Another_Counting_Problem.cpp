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
ll gcd( ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void  solve()
{
    ll a,b,q;cin>>a>>b>>q;
    a=min(a,b);
    b=max(a,b);
    
    
    REP(i,0,q)
    {
        ll l,r;cin>>l>>r;
        l=min(l,r);
        r=max(l,r);
        ll val=lcm(a,b);
        ll count=0;
        ll l1=l/val;ll l2=r/val;
        if(l1!=0)
        {
            ll val1=min((l1*val)+(b),r+1)-l;
            if(val1<0)
            val1=0;
            ll val2=0;
            if(l1!=l2)
            {
                val2=r-(l2*val)+1;
                if(val2>0)
                {
                    val2=min(val2,b);
                }
                if(val2<=b && val2>=1)
                {
                
                }
                else
                {
                    val2=0;
                }
            }
            count+=val1+val2+ b*max((ll)0,(l2-l1-1));
        }
        else
        {
            ll val1=min(b,r+1)-l;
            if(val1<0)
            {
                val1=0;
            }
            ll val2=0;
            if(l1!=l2)
            {
                val2=r-(l2*val)+1;
                if(val2>b)
                {
                    val2=b;
                }
            }
            count+=val1+val2+b*max((ll)0,(l2-l1-1));
        }
        cout<<r-l+1-count<<" ";
    }
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