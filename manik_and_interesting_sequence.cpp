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
void pri(vi arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return;
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n,m;
    cin>>n>>m;
    vi result;
    if(m<n)
    {
        cout<<"No";
        return;
    }
    if(n==1)
    {
        cout<<"Yes\n";
        cout<<m;
        return;
    }
    if(n%2==0 && m&1)
    {
        cout<<"No";
        return;
    }
    if(n%2==0)
    {
        REP(i, 0, n - 2)
        {
            result.pb(1);
        }
        int val=m-n+1;
        result.pb((m - (n) + 2)/2);
        result.pb((m - (n) + 2)/2);
    }
    else
    {
        REP(i, 0, n - 1)
        {
            result.pb(1);
        }
        result.pb((m - (n) + 1));
    }
    cout<<"Yes\n";
    pri(result);
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