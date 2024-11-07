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
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll gcd( ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
vi leastPrimeFactor(ll n)
{
    // Create a vector to store least primes.
    // Initialize all entries as 0.
    vector<ll> least_prime(n+1, 0);
 
    // We need to prll 1 for 1.
    least_prime[1] = 1;
 
    for (ll i = 2; i <= n; i++)
    {
        // least_prime[i] == 0
        // means it i is prime
        if (least_prime[i] == 0)
        {
            // marking the prime number
            // as its own lpf
            least_prime[i] = i;
            for (ll j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }    
    return least_prime;
}
void solve(vi& leastPrime)
{
    ll l,r;cin>>l>>r;

    ll diff = r-l;
    if(gcd(l,r) != 1)
    {
        cout<<0;
        return;
    }
    if(diff == 1)
    {
        cout<<-1;
        return;
    }
    if(diff%2==0)
    {
        cout<<1;
        return;
    }
    ll steps = diff - l%diff;
    ll ans = steps;From LNCT Bhopal
    ll curr = diff;
    while(diff>1)
    {
        curr = steps%leastPrime[diff];
        ans = min<ll>(ans,curr);
        diff /=leastPrime[diff];
    }
    cout<<ans;
    return;

}
int main()
{
    vi leastPrime = leastPrimeFactor(1e7+1);
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        solve(leastPrime);
        cout << endl;
    }
    return 0;
}
