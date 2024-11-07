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
ll closestMultiple(ll n, ll x) 
{    
    if(x>n) 
       return x; 
  
    n = n + x/2; 
    n = n - (n%x); 
    return n; 
} 
void dfs(vi& brr,vi& arr, ll idx)
{
    ll n = arr.size();
    if(idx+1<n)
    {
        if(brr[idx+1]==-1)
        {
            
            dfs(brr,arr,idx+1);
        }
    }
    else if(idx-1>=0)
    {
        if(brr[idx-1]==-1)
        {
            ll ele1 = closestMultiple(brr[idx],arr[idx-1]);
            ll ele2 = closestMultiple(arr[idx-1],brr[idx]);
            if(abs(arr[idx-1]-ele1)<abs(arr[idx-1]-ele2))
            {
                brr[idx-1] = ele1;
            }
            else
            {
                brr[idx-1] = ele2;
            }
            dfs(brr,arr,idx-1);
        }
    }
    return;
}
void solve()
{
    ll n;cin>>n;
    vi arr(n);
    ll sum = 0;
    REP(i,0,n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    REP(i,0,n)
    {
        vi brr(n,-1);
        brr[i] = arr[i];
        dfs(brr,arr,i);
        ll val = 0;
        REP(i,0,n)
        {
            val += abs(arr[i]-brr[i]);
        }
        val*=2;

        if(val<=sum)
        {
            REP(i,0,n)
            {
                cout<<brr[i]<<" ";
            }
            return;
        }
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
