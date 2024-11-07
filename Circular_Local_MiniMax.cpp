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
    input
    sort(arr.begin(),arr.end());
    if(n&1)
    {
         cout<<"NO";
        return;
    }
    vi result;
    ll s=0;
    ll e=n/2;
    while(s<n/2 && e<n)
    {
        result.pb(arr[s]);
        s++;
        result.pb(arr[e]);
        e++;
    }
    REP(i,0,n)
    {
        if(i%2==0)//even
        {
            ll val=(i-1)%n;
            if(val<0)
            {
                val+=n;
            }
            if(result[i+1]<=result[i] || result[val]<=result[i])
            {
                cout<<"NO";
                return;
            }
        }
        else//odd
        {
            ll val=(i-1)%n;
            if(val<0)
            {
                val+=n;
            }
            if(result[(i+1)%n]>=result[i] || result[val]>=result[i])
            {
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES\n";
    REP(i,0,n)
    {
        cout<<result[i]<<" ";
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