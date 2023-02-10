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
void adjacent(vi &arr,int n)
{
    for(int i=0;i<2*n;i+=2)
    {
        swap(arr[i],arr[i+1]);
    }
    return;
}
void nswap(vi &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        swap(arr[i],arr[n+i]);
    }
    return;
}
bool is_sorted(vi &arr,int n)
{
    for(int i=0;i<2*n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return false;
        }
    }
    return true;
}
bool equal(vi &arr,vi &list,int n)
{
    for(int i=0;i<2*n-1;i++)
    {
        if(list[i]!=arr[i])
        {
            return false;
        }
    }
    return true;
}
void  solve()
{
    int n;cin>>n;
    vi list; vi arr;
    REP(i,0,2*n)
    {
        int ele;
        cin>>ele;
        list.pb(ele);
    }
    ll step1=0,step2=0;
    arr=list;
    if(is_sorted(arr,n))
    {
        cout<<step1;
        return;
    }
    while(1)
    {
        //adjacent
        adjacent(arr,n);
        step1++;
        if(is_sorted(arr,n))
        {
            break;
        }
        if(equal(arr,list,n))
        {
            cout<<-1;
            return;
        }
        //n swap
        nswap(arr,n);
        step1++;
        if(is_sorted(arr,n))
        {
            break;
        }
        if(equal(arr,list,n))
        {
            cout<<-1;
            return;
        }
        
    }
    arr=list;
    while(1)
    {
        //n swap
        nswap(arr,n);
        step2++;
        if(is_sorted(arr,n))
        {
            break;
        }
        if(equal(arr,list,n))
        {
            cout<<-1;
            return;
        }
        //adjacent
        adjacent(arr,n);
        step2++;
        if(is_sorted(arr,n))
        {
            break;
        }
        if(equal(arr,list,n))
        {
            cout<<-1;
            return;
        }        
    }
    cout<<min(step1,step2);
    return;
}
int main()
{
    ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}