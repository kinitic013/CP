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
int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
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
    vector<bool> arr=SieveOfEratosthenes(n);
    vi a;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i])
        {
            a.pb(i);
        }
    }
    vi ans;
    REP(i,0,a.size())
    {
        ans.pb(a[i]);
        ll val=a[i];
        while(val<n)
        {
            val*=a[i];
            if(val<=n)
            ans.pb(val);
        }
    }
    cout<<ans.size()<<endl;
    REP(i,0,ans.size())
    {
        cout<<ans[i]<<' ';
    }
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
