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
    ll n;cin>>n;
    input
    ll plus=arr[0];
    bool flag=false;
    REP(i,1,n)
    {
        if(plus<0)
        {
            cout<<"No";
            return;
        }
        if(plus==0 )
        {
            flag=true;
        }
        if(flag && arr[i]!=0)
        {
            cout<<"No";
            return;
        }
        plus+=arr[i];
        
    }
    if(plus!=0)
    {
        cout<<"No";
        return;
    }
    cout<<"Yes";
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