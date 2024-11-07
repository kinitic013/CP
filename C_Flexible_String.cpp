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
#define vpii vector<pii>
#define pairMinHeap priority_queue<pii , vpii, greater<pii> > 
#define all(x) (x).begin(), (x).end()
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define revREP(i,a,b) for (ll i = a ; i>b ; i--)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll ans = 0;
ll calculate(string& a, string& b,vector<ll>& hash)
{
    ll n = a.size();
    ll count = 0;
    ll curr=0;
    REP(i,0,n)
    {
        if(a[i] == b[i] || hash[a[i] - 'a'])
        {
            curr++;
        }
        else
        {
            count += (curr*(curr+1))/2;
            curr=0;
        }
    }
    count += (curr*(curr+1))/2;

    return count;
}
void generate(string& a , string& b ,vector<ll>& arr,string& unique,ll k,ll idx,ll count)
{
    if(count>k )
    return;

    if(count == k)
    {
        ll curr = calculate(a,b,arr);
        ans = max<ll>(curr,ans);
        return;
    }

    if( idx>=unique.size())
    return;

    arr[unique[idx]-'a'] = 1;
    generate(a,b,arr,unique,k,idx+1,count+1);
    arr[unique[idx]-'a'] = 0;
    generate(a,b,arr,unique,k,idx+1,count);
}
void solve()
{
    ll n,k;cin>>n>>k;
    string a,b;cin>>a>>b;
    map<char,ll> m;
    string unique;
    ll count = 0;
    REP(i,0,n)
    {
        auto it = m.find(a[i]);
        if(it==m.end())
        {
            count++;
            m[a[i]] = count;
            unique.pb(a[i]);
        }
    }
    k = min<ll>(k,unique.size());
    vector<ll> arr(26,0);
    ans = calculate(a,b,arr);
    generate(a,b,arr,unique,k,0,0);
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
        cout<<ans;
        ans = 0;
        cout << endl;
    }
    return 0;
}