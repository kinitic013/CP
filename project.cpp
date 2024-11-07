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
bool cmps(vi &a, vi &b)
{
    if(a[1]!=b[1])
    return a[1]<b[1];
    else 
    return a[2]>=b[2];
}
void solve()
{
    int n;cin>>n;
    vector<vi> arr;
    REP(i,0,n)
    {
        vi temp(3);
        cin>>temp[0]>>temp[1]>>temp[2];
        arr.pb(temp);
    }
    sort(all(arr),cmps);
    map<ll,ll> m;
    ll ans = arr[0][2];
    m.insert({arr[0][1],arr[0][2]});
    REP(i,1,n)
    {
        auto it = m.lower_bound(arr[i][0]);
        if(it == m.begin())
        {
            auto add = m.upper_bound(arr[i][1]);
            add--;
            ll val =arr[i][2];
            m[arr[i][1]] = max<ll>(add->ss,val);
            ans = max<ll>(ans,m[arr[i][1]]);
            continue;
        }
        it--;
        auto add = m.upper_bound(arr[i][1]);
        add--;
        ll val = it->ss + arr[i][2];
        m[arr[i][1]] = max<ll>(add->ss,val);
        ans = max<ll>(ans,m[arr[i][1]]);
    }
    cout<<ans;
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
