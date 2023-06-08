#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,q;cin>>n>>q;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    vi flag(n,0);

    REP(i,2,n)
    {
        if(arr[i-2]>=arr[i-1] && arr[i-1]>=arr[i])
        {
            flag[i]=1;
        }
    }
    vi counter(n,0);
    REP(i,1,n)
    {
        counter[i]=flag[i]+counter[i-1];
    }
    REP(i,0,q)
    {
        ll l,r;cin>>l>>r;
        l--;r--;
        ll ans=r-l+1;
        if(r-l>=2)
        {
            ans-=(counter[r]-counter[l+1]);
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}