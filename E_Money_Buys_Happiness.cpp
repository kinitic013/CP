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
    int m,x;cin>>m>>x;
    vpii arr(m);
    ll sum = 0;
    REP(i,0,m) 
    {
        cin>>arr[i].ff>>arr[i].ss;
        sum += arr[i].ss;
    }
    // vi dp(1e5+1,-1);
    ll ans = 0;
    vi dp(sum+1,-1);
    dp[0] = 0;
    if(arr[0].ff == 0)
    {
        dp[arr[0].ss] = 0;
        ans = max<ll>(ans , arr[0].ss);
    }

    REP(i,1,m)
    {
        for(int j = sum ; j>=0;j--)
        {
            if(dp[j] != -1)
            {
                // spending 
                if((dp[j] + x) >= arr[i].ff)
                {
                    dp[j+arr[i].ss] = max<int>(dp[j+arr[i].ss],(dp[j] + x - arr[i].ff));
                }
                // saving this month's salary
                dp[j] = dp[j] + x;
            }
        }
    }
    for(int i = sum ;i>=0;i--)
    {
        if(dp[i]!=-1)
        {
            cout<<i;
            break;
        }
    }
    // cout<<ans;
    return;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}