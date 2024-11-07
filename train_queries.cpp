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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> q;
    map<ll,pair<ll,ll>> arr;
    input

    REP(i,0,k)
    {
        ll a,b;
        cin>>a>>b;
        q.pb({a,b});
    }
    REP(i,0,n)
    {
        ll f=arr[list[i]].ff;
        if(f==0)//first time
        {
            arr[list[i]].ff=i+1;
            arr[list[i]].ss=i+1;
        }
        else
        {
            arr[list[i]].ss=i+1;
        }
    }
    REP(i,0,k)
    {
        auto a=q[i].first;
        auto b=q[i].second;
        auto it1=arr.find(a);
        auto it2=arr.find(b);
        if(it1==arr.end())
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(it2==arr.end())
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        if((it1->ss.ff)<=(it2->ss.ss))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


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
    }
    return 0;
}