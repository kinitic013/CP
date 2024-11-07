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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vi a(n), b(n), c(m);
    REP(i, 0, n)
        cin >> a[i];
    REP(i, 0, n)
        cin >> b[i];
    REP(i, 0, m)
        cin >> c[i];

    multimap<ll, ll> same;
    multimap<ll, ll> notSame;
    REP(i, 0, n)
    {
        if (a[i] == b[i])
            same.insert({a[i], i + 1});
        else
            notSame.insert({b[i], i + 1});
    }
    vi result(m);
    REP(i, 0, m)
    {
        auto it = notSame.find(c[i]);
        if (it != notSame.end()) // present in notSame
        {
            pii ele = {it->ff, it->ss};
            result[i] = ele.ss;
            same.insert(ele);
            notSame.erase(it);
            continue;
        }
        it = same.find(c[i]);
        if (it != same.end()) // present in same
        {
            result[i] = it->ss;
            continue;
        }
        result[i] = -1;
        continue;
    }
    if(notSame.size()>=1)
    {
        cout<<"NO";
    }
    else if (result[m - 1] == -1)
        cout << "NO";
    else
    {
        for (int i = m - 2; i >= 0; i--)
        {
            if (result[i] == -1)
                result[i] = result[i + 1];
        }
        cout << "YES\n";
        REP(i, 0, m)
        {
            cout << result[i] << " ";
        }
    }
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
