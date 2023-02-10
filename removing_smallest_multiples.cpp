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
    ll n;
    string list;
    cin>>n>>list;
    vector<pair<ll,pii>> arr;
    ll setbit=0;ll count=0;
    ll evensetbit=0;
    REP(i,0,n)
    {
        arr.pb({i+1,{list[i]-'0',0}});
        if(list[i]=='1')
        {
            setbit++;
        }

    }
    if(arr[0].ff==0)
    {
        cout<<setbit;
        return;
    }
    REP(i,0,n)
    {
        if(arr[i].ss.ff==0 )// was not present in T
        {
            ll curr=arr[i].ff;
            while(curr<=n)// traversing and checking all factors to remove 
            {
                if(arr[curr-1].ss.ff==0 )//if factor is present in T
                {
                    if(arr[curr-1].ss.ss==0) // if "earlier this element is removed ,but not initially present in T
                    {   
                        count+=arr[i].ff;
                        arr[curr-1].ss.ss=1;
                    }
                    curr=curr+arr[i].ff;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout<<count;
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
