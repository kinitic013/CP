#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ll long long
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
    ll n;cin>>n;vi arr(n);
    REP(i,0,n) cin>>arr[i];
    ll maxi=*max_element(arr.begin(),arr.end());
    vector<pii> count(maxi+1,{0,0});
    REP(i,0,n) count[arr[i]].ss++;
    ll ans=1;
    REP(i,2,maxi+1)
    {
        for(ll j=i;j<=maxi;j+=i)
        {
            if(count[j].ss>=1)
            {

                count[i].ff+=count[j].ss;
                if(count[i].ff>=2)
                {
                    ans=max(ans,i);
                }
            }
        }
    }
    cout<<ans;
    
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
