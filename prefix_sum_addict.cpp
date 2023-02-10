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
    ll n,k;cin>>n>>k;
    vi arr(n,INT_MIN);
    bool flag=0;
    vi pre;
    for(ll i=0;i<k;i++)
    {
        ll ele;
        cin>>ele;
        pre.pb(ele);
        if(i!=0)
        {
            arr[n-k+i]=pre[i]-pre[i-1];
            if(arr[n-k+i]<arr[n-k+i-1])
            {
                flag=1;
            }
        }
        
    }
    if(n==1)
    {
        cout<<"Yes";
        return;
    }
    if(flag)
    {
        cout<<"No";
        return;
    }
    if(n==k)
    {
        arr[0]=pre[0];
        if(n>1 && arr[0]>arr[1])
        {
            cout<<"No";
            return;
        }
        cout<<"Yes";
        return;
    }
    if(k==1)
    {
        cout<<"Yes";
        return;
    }
    ll val=(pre[0]/(n-k+1));
    if(pre[0]<0)
    {
        if(arr[n-k+1]>=0)
        {
            cout<<"Yes";
            return;
        }
    }
    if(pre[0]%(n-k+1)!=0 && pre[0]>=0)
    {
        val++;
    }
    if((pre[0]>=0 && val>arr[n-k+1]))
    {
        cout<<"No";
        return;
    }
    else if(pre[0]<0)
    {
        if(val>arr[n-k+1])
        {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
    return;
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