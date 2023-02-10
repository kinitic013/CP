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
    ll n,a,b;
    cin>>n>>a>>b;
    ll i=1,j=n;
    vi arr;
    if((a+b)>n-2)
    {
        cout<<-1;
        return;
    }
    if(abs(a-b)>1)
    {
        cout<<-1;
        return;
    }
    if(a>b)//max>min
    {
        ll count=0;
        while(count!=a)
        {
            arr.pb(i);
            arr.pb(j);
            i++;
            j--;
            count++;
        }
        while(i<=j)
        {
            arr.pb(j);
            j--;
        }
    }
    else if(b>a)
    {
        ll count=0;
        while(count!=b)
        {
            arr.pb(j);
            arr.pb(i);
            i++;
            j--;
            count++;
        }
        while(i<=j)
        {
            arr.pb(i);
            i++;
        }
    }
    else
    {
        ll count=0;
        while(count!=a)
        {
            arr.pb(i);
            arr.pb(j);
            i++;
            j--;
            count++;
        }
        while(i<=j)
        {
            arr.pb(i);
            i++;
        }

    }
    REP(i,0,n)
    {
        cout<<arr[i]<<" ";
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