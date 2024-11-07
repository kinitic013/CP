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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll n,x;cin>>n>>x;
    vi arr(n+1,0);
    arr[1]=x;
    arr[n]=1;
    REP(i,2,n)
    {
        arr[i]=i;
    }
    if(n==x)
    {
        REP(i,1,n+1)
        {
            cout<<arr[i]<<" ";
        }
        return;
    }
    if(n%x!=0)
    {
        cout<<-1;
        return;
    }
    ll i=x+1;
    ll last=x;
    arr[x]=n;
    while(i<n)
    {
        if(i%last==0 && n%i==0)
        {
            arr[i]=n;
            arr[last]=i;
            last=i;
        }
        i++;
    }
    REP(i,1,n+1)
    {
        cout<<arr[i]<<" ";
    }
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
