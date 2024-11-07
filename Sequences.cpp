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
void dfs(vvi &adj, ll node, vb &visited, vector<map<ll, ll>> &matrix, vi &arr)
{
    visited[node] = 1;
    matrix[matrix.size() - 1][arr[node - 1]]++;
    REP(i, 0, adj[node].size())
    {
        if (!visited[adj[node][i]])
        {
            if (visited[adj[node][i]])
            {
                continue;
            }

            dfs(adj, adj[node][i], visited, matrix, arr);
        }
    }
}
long long power(long long x, ll y, ll p)
{
    long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
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
    for (int i = 2; i <= N; i++)
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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    REP(i, 0, m)
    {
        ll ele1, ele2;
        cin >> ele1 >> ele2;
        adj[ele1].pb(ele2);
        adj[ele2].pb(ele1);
    }
    vi arr(n);
    REP(i, 0, n)
    cin >> arr[i];
    vector<map<ll, ll>> matrix;
    vb visited(n + 1, false);
    REP(i, 1, n + 1)
    {
        if (!visited[i])
        {
            matrix.pb({});
            dfs(adj, i, visited, matrix, arr);
        }
    }
    ll countA = 1;
    vi sz;
    REP(i, 0, matrix.size())
    {
        ll size = 0;
        auto it = matrix[i].begin();
        while (it != matrix[i].end())
        {
            countA = (countA * fact[it->ss]) % MOD;
            size += it->ss;
            it++;
        }
        sz.pb(size);
    }
    ll total = sz[0];
    REP(i, 1, matrix.size())
    {
        ll val = ncr(total+sz[i],sz[i]);
        countA = (countA * val) % MOD;
        total += sz[i];
    }
    cout << countA;
    return;
}
int main()
{
    fast();
    compute();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
