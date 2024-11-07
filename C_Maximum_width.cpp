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
    ll n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    vvi idx(26);
    REP(i,0,n)
    {
        idx[s[i]-'a'].pb(i);
    }
    vvi arr;
    vi last(m,-1);
    last[m-1] = *(--idx[t[m-1]-'a'].end());
    ll ans = LONG_LONG_MIN;
    for(int i= m-2;i>=0;i--)
    {
        auto it = upper_bound(all(idx[t[i]-'a']),last[i+1]);
        it--;
        if(*it == last[i+1])
        it--;

        last[i] = *it;
    }
    ll prev = idx[t[0]-'a'][0];
    ans = max<ll>(ans,last[1]-prev);
    for(int i=1;i<m-1;i++)
    {
        ll first = *upper_bound(all(idx[t[i]-'a']),prev);
        
        ll val = last[i+1]-first;
        ans = max<ll>(ans,val);
        prev = first;
    }
    cout<<ans;
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
