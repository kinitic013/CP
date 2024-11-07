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
/*
If n ≤ 25, the time complexity can be O(2n).
If n ≤ 12, the time complexity can be O(n!).
If n ≤ 100, the time complexity can be O(n4).
If n ≤ 500, the time complexity can be O(n3).
If n ≤ 10**4, the time complexity can be O(n2).
If n ≤ 10**6, the time complexity can be O(n log n).
If n ≤ 10**8, the time complexity can be O(n).
If n > 10**8, the time complexity can be O(log n) or O(1).
*/

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
ll helper(vi& arr,vi& width,int start,int end)
{
    ll n = end+1;
    if(n==1)
    return 0;

    vi pre(n, 0), extra(n, 0);
    pre[start+1] = arr[start+1] + width[start+1];
    extra[start+1] = -(pre[start+1] - width[start+2] + 2) + width[start+2];
    ll maxi = 0;
    maxi = max<ll>(maxi, extra[start+1]);
    ll ans = pre[start+1];
    for (int i = start+2; i < n; i++)
    {
        pre[i] = pre[i - 1] - width[i] + 2 + arr[i];
        ans = max<ll>(ans, pre[i] + maxi);
        ans = max(ans, pre[i]);
        if (i < n - 1)
        {
            extra[i] = -(pre[i] - width[i + 1] + 2) + width[i + 1];

            maxi = max<ll>(maxi, extra[i]);
        }
    }
    ans = max(ans, pre[n - 1] + maxi);
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vi arr(n);
    REP(i, 0, n)
        cin >> arr[i];
    vi width(n);
    REP(i, 0, n)
        cin >> width[i];

    REP(i, 0, n)
    {
        ll ele;
        cin >> ele;
        width[i] = max(ele, width[i]) - min(ele, width[i]) + 1;
    }
    width.pb(1);
    ll ans = 0;
    ll start=0;ll end=0;
    REP(i,0,n)
    {
        if(width[i+1]==1)
        {   end = i;
            ans = max(ans,helper(arr,width,start,end));
            start = end;
            end = i+1;
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
