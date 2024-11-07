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
long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
//seive
vector<ll> SieveOfEratosthenes(ll n)
{
    vector<bool> prime(n+1,true);
    vi res;
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    REP(i,0,prime.size())
    if(prime[i])
    res.pb(i);
    return res;
}
vi leastPrimeFactor(ll n)
{
    // Create a vector to store least primes.
    // Initialize all entries as 0.
    vector<ll> least_prime(n+100, 0);
 
    // We need to print 1 for 1.
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
 
            // mark it as a divisor for all its
            // multiples if not already marked
            for (ll j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }
    return least_prime;
}
bool compare(const pii& p1, const pii& p2) {
  return p1.ff < p2.ff;
}
ll binary_searchh(vector<pii>& v, ll key) {
    ll low = 0;
    ll high = v.size() - 1;

    while (low <= high) {
        ll mid = (low + high) / 2;

        if (v[mid].ff == key) {
        return mid;
        } else if (v[mid].ff < key) {
        low = mid + 1;
        } else {
        high = mid - 1;
        }
    }
    return -1;
}
void solve(vpii& pre,vi& lp)
{
    ll n;cin>>n;
    ll x = binary_searchh(pre,lp[n]);
    ll ans = n*pre[x].ss;
    cout<<ans;
    return;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    vi ans = SieveOfEratosthenes(1e6+10);
    vi lp = leastPrimeFactor(1e6+10);
    vpii pre;
    ll sum = 0;
    REP(i,0,ans.size())
    {
        sum+=ans[i];
        pre.pb({ans[i],sum});
    }

    while (t--)
    {
        solve(pre,lp);
        cout << endl;
    }
    return 0;
}