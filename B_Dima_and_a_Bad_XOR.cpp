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
    int n,m;cin>>n>>m;
    vector<map<ll,ll>> arr;
    REP(i,0,n)
    {
        map<ll,ll> temp;
        REP(j,0,m)
        {
            ll ele;cin>>ele;
            temp[ele]=j+1;
        }
        arr.pb(temp);
    }
    vi res;
    if(n==249 && m == 500)
    {

    }
    ll val = 0;
    bool flag = 0;
    pii extra;
    REP(i,0,n)
    {
        if(arr[i].size()>1)
        {
            flag = 1;
            ll idx = (--arr[i].end())->ss;
            extra = {i,idx};
        }
        res.pb(arr[i].begin()->ss);
        val = val ^ (arr[i].begin()->ff);
    }
    if(val == 0 && flag == 0)
    cout<<"NIE";
    else 
    {
        cout<<"TAK";
        cout<<endl;
        REP(i,0,n)
        {
            if(val == 0 && extra.ff == i)
            {
                cout<<extra.ss<<" ";
            }
            else
            cout<<res[i]<<" ";
        }
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
