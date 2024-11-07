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
    ll n,k;cin>>n>>k;
    string temp;cin>>temp;
    string arr = "#";
    arr = arr + temp;
    vi l(k),r(k);

    REP(i,0,k)
    cin>>l[i];
    REP(i,0,k)
    cin>>r[i];

    ll q;cin>>q;
    vi query(q);
    REP(i,0,q)
    cin>>query[i];

    sort(all(query));
    vi diff(n+2);
    vi sum(n+2,0);
    ll i = 0;
    ll j = 0;
    vector<char> result(n+2);
    while(i<k)
    {
        diff[l[i]] = 0;
        if(l[i]-1>=0)
        sum[l[i]-1] = 0;

        while(j<q)
        {
            ll x = query[j];
            if(!(x<=r[i] && x>=l[i]))
            break;

            ll a = min<ll>(x,r[i]+l[i]-x);
            ll b = max<ll>(x,r[i]+l[i]-x); 
            diff[a]++;
            diff[b+1]--;
            j++;
        }
        ll it = l[i];
        while(it<=r[i])
        {
            sum[it] = sum[it-1] + diff[it];
            if(sum[it]&1)
            {
                result[r[i]+l[i]-it] = arr[it]; 
            }
            else
            {
                result[it] = arr[it];
            }
            it++;
        }
        i++;
    }
    REP(i,1,n+1)
    cout<<result[i];
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