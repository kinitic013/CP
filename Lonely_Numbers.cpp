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
//seive
vector<bool> SieveOfEratosthenes(ll n)
{
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}
void  solve()
{
    ll n;cin>>n;
    vector<bool> isprime=SieveOfEratosthenes((ll)1e6);
    vi limit((ll)1e6+1,(ll)1e6);
    limit[1]=(ll)1e6+1;
    REP(i,2,(ll)1e6+1)
    {
        if(isprime[i])
        {
            limit[i]=i*i;
            if(i<(ll)(1e3)+1)
            limit[i*i]=i;
            continue;
        }
        else
        {
            REP(j,2,i+1)
            {
                if(i%j==0)
                {
                    ll val=(j*j)-j+i;
                    limit[i]=min(limit[i],val);
                    limit[limit[i]]=min(limit[limit[i]],i);
                    break;
                }
            }
        }

    }
    vi arr(n);
    REP(i,0,n) cin>>arr[i];

}
int main()
{

    {
        solve();
        cout<<"\n";
    }
    return 0;
}
