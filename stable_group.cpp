#include<bits/stdc++.h>
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
void  solve()
{
    ll n,k,x;cin>>n>>k>>x;
    int arr[200000];
    REP(i,0,n)
    {
        cin>>arr[i]; 
    }
    sort(arr,arr+n);
    if(n==1)
    {
        cout<<1;
        return;
    }
    int diff[20000];
    int size=0;
    REP(i,0,n-1)
    {
        if(arr[i+1]-arr[i]>x)
        {
           diff[size]=arr[i+1]-arr[i];
           size++;
        }
    }
    if(k==0)
    {
        cout<<size+1;
        return;
    }
    sort(diff,diff+size);
    ll count=size+1;
    REP(i,0,size)
    {
        ll val=(diff[i]/(2*x));
        if(diff[i]%(2*x)!=0)
        {
            val++;
        }
        if(k-val<0)
        {
            break;
        }
        else
        {
            k-=val;
            count--;
        }
    }
    cout<<count;
    return ;
}
int main()
{
    {
        solve();
        cout<<"\n";
    }
    return 0;
}