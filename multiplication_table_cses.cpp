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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
bool check(ll n,ll x,ll limit)
{
    ll count=0;
    REP(i,1,min(n,x)+1)
    {
        ll val=x/i;
        if(val>n)
        {
            count+=n;
        }
        else
        {
            if(x%i==0)
            {
                val--;
            }
            count+=val;
        }
    }
    if(count>=limit)
    return false;
    else 
    return true;
}
void  solve()
{
    ll n;cin>>n;
    ll l=1,r=(n*n);
    ll limit=(r+1)/2;
    ll counter=log2(r+1)+10;
    ll ans=l;
    while(counter--)
    {
        ll x=(l+r)/2;
        bool checker=check(n,x,limit);
        if(checker)
        {
            ans=max(x,ans);
            l=x;
        }
        else
        {
            r=x;
        }
    }
    cout<<ans;
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
