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
    return a.ss < b.ss;
}
ll checker(string &a, string &b, ll idx)
{
    ll count = 0;
    ll n = a.size();
    REP(i, 0, n)
    {
        if (i == idx)
            continue;

        if (a[i] != b[i])
        {
            count++;
            // if(count >= 2)
            // return count;
        }
    }
    return count;
}
void solve(ll t)
{
    ll n, m;
    cin >> n >> m;
    vector<string> arr;
    REP(i, 0, n)
    {
        string temp;
        cin >> temp;
        arr.pb(temp);
    }
    // if (t == 88)
    // {
    //     cout << "test case" << endl;
    //     cout << n << " " << m << endl;
    //     REP(i, 0, n)
    //     {
    //         cout<<arr[i]<<endl;
    //     }
    //     return;
    // }
    REP(i, 0, m)
    {
        ll idx = i;
        string str = arr[0];
        bool flag = false;
        bool failed = false;
        bool pre = 0;
        REP(j, 0, n)
        {
            ll check = checker(arr[0], arr[j], i);
            if (check >= 2)
            {
                failed = true;
                break;
            }
            if(arr[0][idx] != arr[j][idx] && pre)
            {
                failed = true;
                break;
            }
            if (arr[0][idx] != arr[j][idx] && check == 1)
            {
                if (flag)
                {
                    failed = true;
                    break;
                }
                flag = true;
                arr[0][idx] = arr[j][idx];
            }
            if (check == 1 && !flag)
            {
                pre = 1;
            }
        }
        if (!failed)
        {
            cout << arr[0];
            return;
        }
        arr[0] = str;
    }
    cout << -1;
    return;
}
int main()
{
    fast();
    ll t;
    cin >> t;
    REP(i, 1, t + 1)
    {
        solve(i);
        cout << endl;
    }
    return 0;
}
