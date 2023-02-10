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
    ll s=0;
    ll e=n-1;
    ll l=arr[s];
    ll r=arr[e];
    ll count=0;
    ll curr=0;
    while(s<e)
    {
        if(l<r)
        {
            s++;
            l+=arr[s];
        }
        else if(l>r)
        {
            e--;
            r+=arr[e];
        }
        else//l==r
        {
            count=n-e+s+1;
            if(arr[s+1]<arr[e-1] && (s+1<e) && (e-1)>s)
            {
                s++;
                l+=arr[s];
            }
            else if((s+1<e) && (e-1)>s)
            {
                e--;
                r+=arr[e];
            }
            else
            {
                break;
            }
        }

    }
    cout<<count;
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