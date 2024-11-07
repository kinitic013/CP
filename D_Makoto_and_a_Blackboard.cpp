#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vb vector<bool>
#define vpii vector<pii>
#define pairMinHeap priority_queue<pii , vpii, greater<pii> > 
#define all(x) (x).begin(), (x).end()
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define revREP(i,a,b) for (ll i = a ; i>b ; i--)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vpii primeFactors(ll n)
{
    vpii ans;
    // Prll the number of 2s that divide n
    if(n%2==0)
    {
        ans.pb({2,0});
    }
    while (n % 2 == 0)
    {
        ll last = ans.size() - 1;
        ans[last].ss++;
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0)
        {
            ans.pb({i,0});
        }
        while (n % i == 0)
        {
            ll last = ans.size() - 1;
            ans[last].ss++;
            n = n/i;
        }
    }
    if (n > 2)
    ans.pb({n,1});
    
    return ans;
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

// Returns n^(-1) mod p
ll modInverse(long long n, ll p)
{
    return power(n, p - 2, p);
}
ll helper(ll p , ll r , ll n , ll k )
{
    vi powers(r+1,1);
    vi pre(r+1,0);
    REP(i,1,r+1)
    {
        powers[i] = (powers[i-1]*p)%MOD;
    }
    vvi dp(r+1,vi(k+1,0));
    REP(i,0,r+1)
    {
        dp[i][0] = powers[i];
    }
    REP(i,0,r+1)
    {
        if(i-1>=0)
        pre[i] = pre[i-1];
        pre[i] = (pre[i] + dp[i][0])%MOD;
    }
    REP(K,1,k+1)
    {
        vi curr(r+1,0);
        REP(i,0,r+1)
        {
            ll multi = modInverse(i+1,MOD);
            dp[i][K] =(pre[i]*multi)%MOD;
            if(i-1>=0)
            curr[i] = curr[i-1];
            curr[i] = (curr[i] + dp[i][K])%MOD;
        }
        pre = curr;
    }
    return dp[r][k];
}
void solve(ll t)
{
    ll n,k;
    cin>>n>>k;
    vpii primes = primeFactors(n);
    ll size = primes.size();
    ll ans = 1;
    REP(i,0,size)
    {
        ll val = helper(primes[i].ff,primes[i].ss,n,k);
        ans = (ans*val)%MOD;
    }
    cout<<ans;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll t;
    // cin >> t;
    // REP(T,1,t+1)
    {
        solve(1);
        cout << endl;
    }
    return 0;
}