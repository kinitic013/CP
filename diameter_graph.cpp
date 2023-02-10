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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
 
//     REP(i,0,n)
//     {
//         ll ele;
//         cin>>ele;
//         x.pb(ele);
//     }
 
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    if(k<2)
    {
        cout<<"NO";
        return;
    }
    if(k==2)//diameter 0
    {
        if(n==1 && m==0)
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }
    if(k==3)//diameter 1
    {
        if(m==(n*(n-1))/2)
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }
    if(k>=4)//diameter 2 or more
    {
        ll min=n-1;
        if(m>=min && m<=(n*(n-1)/2))
        cout<<"YES";
        else
        cout<<"NO";
        return;
    }
    return ;
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