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
    if(a.ss!=b.ss)
    return a.ss > b.ss;
    else
    return a.ff<=b.ff;
}
// as cost of each product is same purchasing more than needed to get discount cost 1 extra to total cost and that 1 is compensated
// by the discount we get(or try to achieve on to the next product) so BUY ONLY THAT'S NEEDED
void solve()
{
    ll n;cin>>n;
    ll total = 0;
    vector<pii> arr(n,{0,0});
    REP(i,0,n)
    {
        cin>>arr[i].ff>>arr[i].ss;
        total += arr[i].ff;
    }
    sort(all(arr),cmps);
    ll i = total;
    ll count = 0;
    REP(j,0,n)
    {
        if(arr[j].ss>=i)
        continue;
        else
        {
            ll val = min<ll>(arr[j].ff,i-arr[j].ss);
            i -= val;
            count+=val;
        }
    }
    ll result = count + (total - count)*2;
    cout<<result;
    return;
}
int main()
{
    fast();
    // ll t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
