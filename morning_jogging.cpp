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

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n,m;cin>>n>>m;
    vector<vector<ll>> arr(101,vector<ll>(101));
    vector<pii>memset;//storing element, tag inbetween , initial runner pos

    REP(i,0,n)
    {
        REP(j,0,m)
        {
            int ele;cin>>ele;
            memset.pb({ele,i});
        }
    }
    sort(memset.begin(),memset.end());
    auto it=memset.begin();
    REP(i,0,m)
    {
        arr[it->second][i]=it->first;
        it++;
        //        initial pos,     min element,
    }
    while(it!=memset.end())
    {
        ll idx=0;
        while(arr[it->ss][idx]!=0)
        {
            idx++;
        }
        arr[it->ss][idx]=it->ff;
        it++;
    }
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
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
    }
    return 0;
}