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
#define vip vector<pii>
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ff>b.ff;
}

void  solve()
{
    ll n,w;cin>>n>>w;
    vip arr;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        arr.pb({ele,i+1});
    }
    sort(arr.begin(),arr.end(),cmps);
    vi result;
    ll count=0;bool flag=0;
    REP(i,0,n)
    {
        if(arr[i].ff<=w)
        {
            count+=arr[i].ff;
            result.pb(arr[i].ss);
        }
        if(count>=((w/2)+(w%2)))
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<result.size()<<"\n";
        REP(i,0,result.size())
        {
            cout<<result[i]<<" ";
        }
        return;
    }
    else
    cout<<-1;

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
