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
    string arr;
    cin>>arr;
    ll r=0,b=0;
    bool flag=0;
    if(n==1 )
    {
        if(arr[0]!='W')
        cout<<"NO";
        else
        cout<<"YES";
        return;
    }
    ll i=0;
    for(;i<n;i++)
    {
        if(arr[i]=='W' && arr[i-1]!='W' && i!=0)
        {
            if((b==0 || r==0) && flag)
            {
                cout<<"NO";
                return;
            }
            b=0;
            r=0;
        }
        else if(arr[i]=='B')
        {
            flag=1;
            b++;
        }
        else if(arr[i]=='R')
        {
            flag=1;
            r++;
        }
    }
    if((r==0 || b==0)&& arr[i-1]!='W' && flag)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES";
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