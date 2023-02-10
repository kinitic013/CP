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
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n;
    cin>>n;
    vi arr;
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        arr.pb(ele);
    }
    
    vi fre(n,0);
    vi curr(n,0);
    int count=0;
    REP(i,0,n)
    {
        curr[arr[i]]++;
        fre[arr[i]]++;
        count++;
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