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
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> result;
    input
    if(arr[n-2]>arr[n-1] )
    {
        cout<<-1;
        return;
    }
    if(arr[n-1]<0)
    {
        REP(i,0,n-1)
        {
            if(arr[i]>arr[i+1])
            {
                cout<<"-1";
                return;
            }
        }
        cout<<0;
        return;
    }
    bool flag=0;
    REP(i,0,n-1)
    {
        if(arr[i]>arr[i+1])
        {
            flag=1;
            break;

        }
    }
    if(!flag)
    {
        cout<<0;
        return;
    }
    cout<<n-2<<'\n';
    REP(i,0,n-2)
    {
        cout<<i+1<<" "<<n-1<<" "<<n<<'\n';
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