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
ll power(ll x, ll y,  ll M)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
 
// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll modInverse(ll A, ll M)
{
    return power(A, mod - 2, mod);
}
ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;
 
    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}
void solve()
{
    ll n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    ll denominator = (modFact((n/6),mod));
    denominator = (denominator*denominator)%mod;
    ll count = (modFact(n/3,mod)*modInverse(denominator,mod))%mod;
    for(int i=0;i<n;i+=3)
    {
        if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])
        {
            count = (count*3)%mod;
        }
        else
        {
            ll maxi = max<ll>(arr[i],max<ll>(arr[i+1],arr[i+2]));
            if(arr[i] == arr[i+1])
            { 
                if(arr[i]!=maxi)
                {
                    count =( count*2)%mod;
                }
            }
            else if(arr[i+2] == arr[i])
            {
                if(arr[i]!=maxi)
                {
                    count =( count*2)%mod;
                }
            }
            else if(arr[i+1] == arr[i+2])
            {
                if(arr[i+1]!=maxi)
                {
                    count =( count*2)%mod;
                }
            }
        }
    }
    cout<<count;
    return;
}
int main()
{
    fast();
    // ll t;
    // // cin >> t;
    // // while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
