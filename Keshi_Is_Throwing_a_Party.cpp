#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
bool checker(vi a,vi b,vi arr,ll x)
{
    vector<pii> temp;
    REP(i,0,arr.size())
    {
        pii rich;
        rich.ff=(x-a[i]);
        rich.ss=x;
        pii poor;
        poor.ff=1;
        poor.ss=b[i]+1;
        temp.pb({max(rich.ff,poor.ff),min(rich.ss,poor.ss)});
    }
    
}
void  solve()
{

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
