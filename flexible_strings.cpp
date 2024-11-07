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
void makeCombiUtil(vector<vector<ll> >& ans,
    vector<ll>& tmp, ll n, ll left, ll k)
{
    // Pushing this vector to a vector of vector
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
 
    // i iterates from left to n. First time
    // left will be 1
    for (ll i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}

vector<vector<ll> > makeCombi(ll n, ll k)
{
    vector<vector<ll> > ans;
    vector<ll> tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    set<ll> s;
    REP(i, 0, n)
    {
        if (a[i] != b[i])
        {
            s.insert(a[i] - 'a');
        }
    }
    vvi ans;
    vi tmp;
    auto it = s.begin();
    while (it != s.end())
    {
        tmp.pb(*it);
        it++;
    }
    ll dist = s.size();
    ll count = 0;

    ans = makeCombi()
    return ;
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
