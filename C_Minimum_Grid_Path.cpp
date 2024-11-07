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
void solve()
{
    ll n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    ll ans = LONG_LONG_MAX;
    priority_queue <ll, vector<ll>, greater<ll>> even;
    priority_queue <ll, vector<ll>, greater<ll>> odd;
    ll evenSum = 0;
    ll oddSum = 0;
    even.push(arr[0]);
    odd.push(arr[1]);
    evenSum = arr[0];
    oddSum = arr[1];
    ans = (n - even.size() + 1)*even.top() + (n-odd.size() + 1)*odd.top() + evenSum + oddSum - even.top() - odd.top();
    REP(i,2,n)
    {
        if(i%2==0)//even
        {
            even.push(arr[i]);
            evenSum+=arr[i];
            ll val = (n - even.size() + 1)*even.top() + (n-odd.size() + 1)*odd.top() + evenSum + oddSum - even.top() - odd.top();
            ans = min<ll>(ans,val);
        }
        else
        {
            odd.push(arr[i]);
            oddSum+=arr[i];
            ll val = (n - even.size() + 1)*even.top() + (n-odd.size() + 1)*odd.top() + evenSum + oddSum - even.top() - odd.top();
            ans = min<ll>(ans,val);
        }
    }
    cout<<ans;
    return;
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
