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
    return a.ss > b.ss;
}
vi Divisors(ll n)
{
    vi ans;
    // Note that this loop runs till square root
    for (ll i = 1; i <= 26; i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, prll only one
            if (n / i == i)
                ans.pb(i);
            else
            {
                if (i <= 26)
                    ans.pb(i);
                if (n / i <= 26)
                    ans.pb(n / i);
            }
        }
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    string arr;
    cin >> arr;
    vector<pii> m(26, {0, 0});
    REP(i,0,26) m[i].ff = i;
    REP(i, 0, n) m[arr[i] - 'a'].ss++;
    sort(all(m), cmps);
    vi factor = Divisors(n);
    ll ans = LONG_LONG_MAX;
    vi swapping(26, 0);

    REP(i, 0, factor.size()) // sqrt(N)
    {
        ll pos = 0;
        ll neg = 0;
        REP(j, 0, factor[i])
        {
            if (m[j].ss - n / factor[i] >= 0)
            {
                pos += m[j].ss - n / factor[i];
            }
            else
            {
                neg += n / factor[i] - m[j].ss;
            }
        }
        ll val = max<ll>(neg, pos);
        if (val < ans)
        {
            swapping = vi(26,0);
            REP(j, 0,26)
            {
                if(j<factor[i])
                swapping[m[j].ff]  = m[j].ss - n / factor[i];
                else
                swapping[m[j].ff]  = m[j].ss ;

            }
        }
        ans = min<ll>(ans, val);
    }
    REP(i,0,n)
    {
        if(swapping[arr[i]-'a']>0)
        {
            swapping[arr[i]-'a']--;
            arr[i] = '?';
        }
    }
    ll j = 0;
    while( j<26 && swapping[j]>=0 )
    j++;

    REP(i,0,n)
    {
        if(arr[i]=='?')
        {
            while(j<26 &&  swapping[j]>=0)
            j++;

            arr[i] = 'a'+j;
            swapping[j]++;
        }
    }
    cout<<ans<<endl;
    cout<<arr;
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
