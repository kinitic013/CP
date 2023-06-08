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
void helper(vi &arr,ll len)
{
    ll i=16;
    while(len--)
    {
        arr.pb(i);
        i++;
    }
}
void  solve()
{
    ll n;cin>>n;
    vi ans;
    if(n%4==0)
    {
        helper(ans,n);
    }
    else if(n%4==1)
    {
        ans.pb(0);
        helper(ans,n-1);
    }
    else if(n%4==3)
    {
        ans.pb(2);
        ans.pb(1);ans.pb(3);
        helper(ans,n-3);
    }
    else 
    {
        ans.pb(2);
        ans.pb(1);ans.pb(3);
        ans.pb(7);
        ans.pb(15);ans.pb(8);
        helper(ans,n-6);
    }
    REP(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    return;

}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}

