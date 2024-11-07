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
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353

void swap(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}
ll msum(ll a, ll b, ll m) { return ((a % m + b % m) + m) % m; }
ll msub(ll a, ll b, ll m) { return ((a % m - b % m) + m) % m; }
ll mpro(ll a, ll b, ll m) { return (((a % m) * (b % m) + m)) % m; }

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
long long my_sqrt(long long a)
{
    long long l = 0, r = 5000000001;
    while (r - l > 1)
    {
        long long mid = (l + r) / 2;
        if (1ll * mid * mid <= a)
            l = mid;
        else
            r = mid;
    }
    return l;
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}

void solve()
{
    ll n,k;cin>>n>>k;
    vi b(n);
    ll pro = 1;
    REP(i,0,n) 
    {
        cin>>b[i];
        pro *= b[i];
    }
    ll remain = 2023/pro;
    if(remain == 2023)
    {
        if(k==1)
        cout<<2023;
        else if(k==2)
        cout<<289<<" "<<
    }
}
int main()
{
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
