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

void  solve()
{
    ll n,m;cin>>n>>m;
    string arr,brr;
    cin>>arr>>brr;
    ll count=0;
    // REP(i,0,n-1)
    // {
    //     if(arr[i]!=arr[i+1])
    //     {
    //         count++;
    //     }
    // }
    // REP(i,0,m-1)
    // {
    //     if(brr[i]!=brr[i+1])
    //     {
    //         count++;
    //     }
    // }
    // if(count!=(m+n)-2)
    // {
    //     cout<<"NO";
    //     return;
    // }
    // if(arr[n-1]==brr[n-1])
    // {
    //     cout<<"NO";
    //     return;
    // }
    for(int i=m-1;i>=0;i--)
    {
        arr.pb(brr[i]);
    }
    REP(i,0,n+m-1)
    {
        if(arr[i]==arr[i+1])
        {
            count++;
        }
    }
    if(count>1)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES";
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
