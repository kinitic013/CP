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
    ll n;
    cin>>n;
    input
    map<ll,vector<ll>> m;
    REP(i,0,n)
    {
        m[arr[i]].pb(i+1);
    }
    auto it=m.begin();
    ll count=0;
    ll result[n+1]={0};
    while(it!=m.end())
    {
        count=0;
        vector<ll> temp=it->ss;
        REP(i,0,temp.size()-1)
        {
            if((temp[i+1]-temp[i])&1)
            {
                count++;
            }
        }
        result[it->ff]=count+1;
        it++;
    }
    REP(i,1,n+1)
    {
        cout<<result[i]<<" ";
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