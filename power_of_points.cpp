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
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}

void solve()
{
    int  n;cin>>n;
    vector<pii> arr;
    REP(i,0,n) 
    {
        ll ele;cin>>ele;
        arr.pb({ele,i});
    }
    sort(all(arr));

    vector<pii> res(n,{0,0});
    REP(i,0,n)
    {
        res[0].ff=arr[0].ss;
        res[0].ss+=(arr[i].ff-arr[0].ff+1);
    }
    REP(i,1,n)
    {
        ll val=(arr[i].ff-arr[i-1].ff)*(2*i-n);
        res[i].ss=res[i-1].ss+val;
        res[i].ff=arr[i].ss;
    }
    sort(all(res));
    REP(i,0,n)
    {
        cout<<res[i].ss<<" ";
    }
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
