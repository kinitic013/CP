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
    ll n,k;
    cin>>n>>k;
    vi arr(n);
    vi left(n);
    vi right(n);
    vb present(k+1,false);
    REP(i,0,n)
    {
        cin>>arr[i];
        present[arr[i]]=1;
    }
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    REP(i,1,n)
    {
        left[i]=max(left[i-1],arr[i]);
    }
    for(ll i = n-2;i>=0;i--)
    {
        right[i] = max(right[i+1],arr[i]);
    }
    reverse(all(right));
    REP(i,1,k+1)
    {
        if(!present[i])
        {
            cout<<0<<" ";
            continue;
        }
        auto l = lower_bound(all(left),i);
        auto r = lower_bound(all(right),i);

        ll idx1 = l-left.begin();
        ll idx2 = n-1-(r-right.begin());

        cout<< 2*(idx2-idx1+1)<<" ";
    }
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
        cout << endl;
    }
    return 0;
}
