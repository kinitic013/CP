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
    ll n;
    cin>>n;
    string str;
    cin>>str;
    ll sum=0;
    REP(i,0,n)
    {
        if(str[i]=='L')
        {
            sum+=i%MOD;
        }
        else
        {
            sum+=(n-i-1)%MOD;
        }
    }
    ll s=0,e=n-1;
    bool flag=false;
    queue<ll>arr;
    while(s<e)
    {
        if(str[s]=='L')
        {
            arr.push(s);
            
        }
        if(str[e]=='R')
        {
            arr.push(e);
           
        }
        s++;
        e--;
    }
    ll j=0;
    for(;j<n;j++)
    {
        if(arr.size()==0)
        {
            flag=true;
            break;
        }
        ll idx=arr.front();
        arr.pop();
        if(idx>=n/2)//right facing optimal
        {
            sum+=(2*idx-n+1)%MOD;   
        }
        else
        {
            sum+=(n-2*idx-1)%MOD;
        }
        cout<<sum<<" ";
    }
    if(flag)
    {
        for(;j<n;j++)
        {
            cout<<sum<<" ";
        }
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