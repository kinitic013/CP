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
void solve()
{
    ll n;cin>>n;
    vi arr(n);
    REP(i,0,n)
    cin>>arr[i];

    vvi result(n,vi(n,0));
    REP(i,0,n)
    {
        result[i][i] = arr[i];
    }
    ll x = 0 ;
    ll y = n-1;
    while(x<=y)
    {
        ll count = 1;
        ll i = x;
        ll j = x;
        while(count!=arr[x])
        {
            if(j-1>=0 && result[i][j-1]==0)//left possible
            {
                count++;
                j--;
                result[i][j] = arr[x];
            }
            else//down possible  if(i+1<n && result[i+1][j]==0)
            {
                count++;
                i++;
                result[i][j] = arr[x];
            } 
        }
        x++;
    }
    REP(i,0,n)
    {
        REP(j,0,i+1)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
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
