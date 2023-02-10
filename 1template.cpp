#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    int n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll ans=LONG_LONG_MAX;
    REP(i,0,n)
    {
        REP(j,i+1,n)
        {
            ll val=abs(arr[i]-2*arr[j]);
            auto it1=lower_bound(arr.begin()+j+1,arr.end(),val);
            auto it2=it1;
            it2--;
            if(it2!=arr.begin()+j && it2!=arr.begin()+i)
            {
                ans=min(ans,3*abs(((arr[i]+arr[j]+*it1)/3)-arr[j]));
            }
            if(it1!=arr.end())
            {
                ans=min(ans,3*abs(((arr[i]+arr[j]+*it2)/3)-arr[j]));
            }
            auto it3=it1;
            it3++;
            if(it3!=arr.end())
            {
                ans=min(ans,3*abs(((arr[i]+arr[j]+*it3)/3)-arr[j]));
            }
        }

    }
    cout<<ans;
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
