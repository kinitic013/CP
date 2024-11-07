#include<bits/stdc++.h>
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
ll find(vi arr,ll key)
{
    REP(j,0,arr.size())
    {
        if(arr[j]==key)
        {
            return j;
        }
    }
    return -1;
}
void Rshift(vi &arr, ll key,ll times)
{
    ll idx=times-1;
    ll n=arr.size();
    times=times%key;
    vi temp;
    //shifted part
    REP(i,idx+1,key)
    {
        temp.pb(arr[i]);
    }
    REP(i,0,times)
    {
        temp.pb(arr[i]);
    }
    REP(i,key+1,n)
    {
        temp.pb(arr[i]);
    }
    arr=temp;
    return;

}

bool dfs_loop(vvi&adj,vb& visited,vb& loop,ll node,ll parent,ll& start)
{
    visited[node] = 1;

    for(auto x:adj[node])
    {
        if(x != parent)
        {
            if(visited[x])
            {
                start = x;
                loop[node] = 1;
                return 1;
            }
            else
            {
                bool check = dfs_loop(adj,visited,loop,x,node,start);
                if(node == start)
                {
                    loop[node] = 1;
                    return false;
                }
                if(check)
                {
                    loop[node] = 1;
                    return check;

                }
            }
        }
    }
    return 0;
}

void helper(vi arr,vector<vector<ll>> &result,ll i)
{
    ll n=arr.size();
    if(i==n)
    {
        return;
    }
    vector<vector<ll>> temp;
	if(result.empty())
	{
		vi seq;
		result.pb(seq);
		seq.pb(arr[i]);
		result.pb(seq);
		helper(arr,result,i+1);
		return;
	}
    REP(j,0,result.size())
    {
        temp.pb(result[j]);
    }
    REP(j,0,result.size())
    {
        result[j].pb(arr[i]);
        temp.pb(result[j]);
    }
    result=temp;
    helper(arr,result,i+1);
	return;
}

ll sqrtt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

vector<vector<ll>> subset(vi arr)
{
    vector<vector<ll>> result;
    ll n=arr.size();
    helper(arr,result,0);
    for(auto temp:result)
    {
        for(auto ele :temp)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return result;
}
vector<bool> sieve_mobius(ll n,vi& um)
{
    um = vi(n+1,1);
    vector<bool> primes(n+1,true);
    primes[1] = 0;
    REP(i,2,n+1)
    {
        if(primes[i])
        {
            for(int j = i ;j<=n;j+=i)
            {
                if(j>i) primes[j] = 0;
                if(j%(i*i)==0) um[j] = 0;
                um[j] = -um[j];
            }
        }
    }
    return primes;
}
ll maxn = 1e6+1;
vector<ll> lp(maxn,0);
void sieve()
{
    lp[1] = 1;
    for(ll i = 2 ; i<maxn ; ++i)
    {
        if(!lp[i])
        {
            lp[i] = i;
            for(ll j=i*i ; j<maxn ; j+=i)
            {   
                if(!lp[j]) lp[j] = i;
            }   
        }
    }
}
vector<ll> count(maxn,0);
vi sievePrimes(ll n)
{
    vi primes;
    ll ele = n;
    while(ele>1)
    {
        ll prime = lp[ele];
        primes.pb(prime);
        while(ele%prime == 0)
        ele /= prime;
    }
    return primes;
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
//Prime cound
vector<ll> PrimeCount(ll n)
{
    vector<bool> arr=SieveOfEratosthenes(n);
    vi ans(n+1,0);
    REP(i,1,n+1)
    {
        if(arr[i])
        {
            ans[i]=ans[i-1]+1;
        }
        else
        {
            ans[i]=ans[i-1];
        }
    }
    return ans;
}


// array containing all divisors
vi Divisors(ll n)
{
    vi ans;
    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, prll only one
            if (n/i == i)
                ans.pb(i);
            else
            {
                ans.pb(i);
                ans.pb(n/i);
            }     
        }
    }
    return ans;
}

// all prime factors of n
vi primeFactors(ll n)
{
    vi ans;
    // Prll the number of 2s that divide n
    if(n%2==0)
    {
        ans.pb(2);
    }
    while (n % 2 == 0)
    {
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0)
        {
            ans.pb(i);
        }
        while (n % i == 0)
        {
            n = n/i;
        }
    }
    if (n > 2)
    ans.pb(n);
    
    return ans;
}
 
// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
// log a to base b
ll log_a_to_base_b(ll a, ll b)
{
    return log2(a) / log2(b);
}
//lcm hcf
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
//random number
ll randomNumber(ll a,ll b){
    return a + (rand() % b);
}

bool IntegerPalindromeCheck(ll n)
{
    string arr=to_string(n);
    ll i=0;ll j=arr.size()-1;
    while(i<=j)
    {
        if(arr[i]!=arr[j])
        return false;
        i++;j--;
    }
    return true;
}
//modular expo
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

///Rolling Hash funciton 

ll rollingHashFunction(string arr)
{
    ll n=arr.size();
    ll MOD=(ll)(1e9+7);
    ll p=31;
    ll prime=p;
    ll hash=0;
    REP(i,0,n)
    {
        ll current=((arr[i]-'a'+1)*prime)%MOD;
        hash=(hash+current)%MOD;
        prime=(prime*p)%MOD;
    }
    return hash;
}

// ncr
#define MOD 1000000007
#define N  200007
ll fact[N + 1];
ll inv[N + 1];
ll invFact[N + 1];
void compute()
{

    inv[0] = inv[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        inv[i] = (inv[MOD % i] * (MOD - MOD / i)) % MOD;
    }

    invFact[0] = invFact[1] = 1;
    for (int  i = 2; i <= N; i++)
    {
        invFact[i] = (invFact[i - 1] * inv[i]) % MOD;
    }

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
ll ncr(ll n, ll k) {
		return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}
vi nextSmallerRight(vi&arr)
{
    int n = arr.size();
    vi res(n,LONG_LONG_MAX);
    stack<ll> s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty())
        {
            ll top = s.top();
            if(arr[top] >= arr[i])
            {
                s.pop();
            }
            else
            {
                res[i] = top;
                break;
            }
        }
        if(res[i] == LONG_LONG_MAX)
        {
            res[i] = n;
        }
        s.push(i);
    }
    // debug(res);
    return res;
}
vi nextSmallerLeft(vi&arr)
{
    int n = arr.size();
    vi res(n,LONG_LONG_MAX);
    stack<ll> s;
    REP(i,0,n)
    {
        while(!s.empty())
        {
            ll top = s.top();
            if(arr[top] >= arr[i])
            {
                s.pop();
            }
            else
            {
                res[i] = top;
                break;
            }
        }
        if(res[i] == LONG_LONG_MAX)
        {
            res[i] = -1;
        }
        s.push(i);
    }
    // debug(res);
    return res;
}
void add(ll &a, ll b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
 
ll sum(ll a, ll b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}
 
ll mul(ll a, ll b) {
    return (a * 1LL * b) % MOD;
}