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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,p;
    cin>>n>>p;
    input
    sort(arr.begin(),arr.end());
    map<ll,ll> pre;
    ll sum=0;
    pre.insert({0,0});
    REP(i,0,n)
    {
        sum+=arr[i];
        pre.insert({sum,i+1});
    }
    REP(i,0,p)
    {
        ll q;
        cin>>q;
        if(q>sum)
        {
            cout<<-1<<'\n';
           continue;
        }
        auto it1=pre.upper_bound(sum-q);
        if(it1==pre.begin())
        {
            cout<<-1<<'\n';
           continue;
        }
        it1--;
        auto it2=pre.end();
        it2--;
        cout<<it2->ss-it1->ss<<'\n';
        continue;
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
        // cout<<"\n";
    }
    return 0;
}