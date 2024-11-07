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
    ll k;
    cin >> k;
    string arr;
    cin >> arr;
    arr.pb('#');
    reverse(all(arr));
    ll n = arr.size();
    vi res(n, 1);
    for (int i = n - 1; i > 0; i--)
    {
        ll idx = 2*i;
        if(idx>=n)// left node
        {
            if(arr[i] == '?')
            res[i] = 2;
            else
            res[i] = 1;
        }
        else
        {
            if(arr[i] == '?')
            {
                res[i] = res[idx] + res[idx+1];
            }
            else if(arr[i] == '0')
            {
                res[i] = res[idx + 1];
            }
            else 
            {
                res[i] = res[idx];
            }
        }
    }
    ll q;cin>>q;
    while(q--)
    {
        ll idx;cin>>idx;
        char val;cin>>val;
        idx = n-idx;
        arr[idx] = val;
        while(idx>0)
        {
            if(idx*2>=n)//left node
            {
                arr[idx] = val;
                if(val == '?')
                res[idx] = 2;
                else
                res[idx] = 1;
            }
            else
            {
                if(arr[idx] == '?')
                {
                    res[idx] = res[idx*2] + res[idx*2 +1];
                }
                else if(arr[idx] == '0')
                {
                    res[idx] = res[idx*2 + 1];
                }
                else 
                {
                    res[idx] = res[idx*2];
                }                
            }
            idx/=2;
        }
        cout<<res[1]<<endl;
    }
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
