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
    ll n;cin>>n;
    ll limit=3+(n-1)*2;
    if(n<=3)
    {
        if(n==1)
        cout<<3;
        else if(n==2)
        cout<<5;
        else if(n==3)
        cout<<7;
        return;
    }
    n-=3;
    ll val=n/3;
    ll end=8+(val)*4;
    if(n%3==0)
    {
        cout<<end-1;
        return;
    }
    else 
    {
        if(n%3==1)
        cout<<end;
        else if(n%3==2)
        cout<<end+1;
        return;
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
