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
    vi arr(1001,0);
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        arr[ele]=i+1;
    }
    ll maxi=-1;
    ll curr=0;
    REP(i,1,1001)
    {
        if(arr[i]!=0)
        {
            REP(j,i,1001)
            {
                curr=__gcd(i,j);
                if(arr[i]!=0 && arr[j]!=0 && curr==1 )
                {
                    maxi=max(maxi,arr[i]+arr[j]);
                }
            }
        }
        
    }
    cout<<maxi;
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