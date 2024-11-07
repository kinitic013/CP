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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n;
    cin>>n;
    vi arr;
    vi odd;vi even;
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        if(ele&1)
        {
            odd.pb(i+1);
        }
        else
        {
            even.pb(i+1);
        }
        arr.pb(ele);
    }
    vector<pair<ll,ll>> result;
    if(arr[0]&1)//odd
    {
        //first homo
        int m=odd.size();
        REP(i,0,m-1)
        {
            result.pb({odd[i],odd[m-1]});
            arr[odd[i]-1]=arr[odd[m-1]-1];
        }
        //hetro
        m=even.size();
        REP(i,0,m)
        {
            result.pb({1,even[i]});
            arr[even[i]-1]=arr[0];
        }
    }
    else //even
    {
        //first homo
        int m=even.size();
        REP(i,0,m-1)
        {
            result.pb({even[i],even[m-1]});
            arr[even[i]-1]=arr[even[m-1]-1];
        }
        //hetro
        m=odd.size();
        REP(i,0,m)
        {
            result.pb({1,odd[i]});
            arr[odd[i]-1]=arr[0];
        }
    }
    cout<<result.size()<<'\n';
    REP(i,0,result.size())
    {
        cout<<result[i].ff<<" "<<result[i].ss<<endl; 
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
