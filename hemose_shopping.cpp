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

//     REP(i,0,n)
//     {
//         ll ele;
//         cin>>ele;
//         x.pb(ele);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,x;cin>>n>>x;
    input
    if(x>(n/2))
    {
        ll s=n-x;
        ll e=min(n-1,x-1);
        ll size=e-s+1;
        REP(i,s,e)
        {
            if(arr[i]>arr[i+1])
            {
                cout<<"NO";
                return;
            }
        }
        ll mini=arr[s];
        ll maxi=arr[e];int mi=0,ma=0;
        for(ll i=0;i<n;)
        {
            if(i==s)
            {
                i=e+1;
                continue;
            }
            if((arr[i]<maxi && arr[i]>mini))
            {
                cout<<"NO";
                return;
            }
            if(arr[i]>=maxi )
            {
                ma++;
            }
            if(arr[i]<=mini)
            {
                mi++;
            }
            i++;
        }
        if(ma<(n+s-e-1)/2 || mi<(n+s-e-1)/2)
        {
            cout<<"NO";
            return;
        }
        cout<<"YES";
        return;
    }
    else
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