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
    ll n,d;cin>>n>>d;
    ll a,b;cin>>a>>b;
    vector<pii> arr;
    REP(i,0,n)
    {
        ll ele1,ele2;cin>>ele1>>ele2;
        arr.pb({(a*ele1)+(b*ele2),i+1});
    }
    sort(arr.begin(),arr.end());
    vi result;
    ll i=0;
    while(d>=0 && i<n)
    {
        if(arr[i].ff<=d)
        {
            result.pb(arr[i].ss);
            d-=arr[i].ff;
        }
        else
        break;
        i++;
    }
    cout<<result.size()<<endl;
    REP(i,0,result.size())
    {
        cout<<result[i]<<" ";
    }
    return;
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
