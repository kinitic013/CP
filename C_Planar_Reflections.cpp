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
    ll n;ll k;cin>>n>>k;
    vector<vi> left(k+1,vi(n+2,0));//particle is on the left size of plane and going to hit 
    vector<vi> right(k+1,vi(n+2,0));
    // REP(i,2,k+1)
    // {
    //     left[i][1] = 1;
    //     right[i][n] = 1;
    // }
    REP(i,2,k+1)
    {
        for(int j=n;j>=1;j--)
        {
            left[i][j] =( 1 + right[i-1][j-1] + left[i][j+1])%MOD;
            right[i][n-j+1] = left[i][j];
        }
    }
    // ll sum = 1;
    // REP(i,1,k+1)
    // {
    //     REP(j,1,n+1)
    //     {
    //         cout<<left[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // REP(i,1,k+1)
    // {
    //     REP(j,1,n+1)
    //     {
    //         cout<<right[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout.flush();
    // REP(i,1,n+1)
    // {
    //     sum+=left[k][i];
    // }
    // cout<<sum;
    cout<<left[k][1]+1;
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
