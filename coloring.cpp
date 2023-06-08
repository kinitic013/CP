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
#define mod (ll)998244353
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,m,k;cin>>n>>m>>k;
    vi arr(m);
    bool flag=0;
    if(k>m)
    {
        flag=1;
    }
    ll val=n/k;
    ll count=0;
    REP(i,0,m) 
    {
        cin>>arr[i];
        if(arr[i]>val)
        {
            if(arr[i]-val>1)
            flag=1;
            
            count++;
        }
    }
    if(count>n%k)
    flag=1;
    if(flag)
    cout<<"NO";
    else
    cout<<"YES";
    return;
    
    // sort(arr.begin(),arr.end(),greater<ll>());
    // map<ll,ll,greater<ll>()> arr;
    // REP(i,0,m) 
    // {
    //     ll ele;cin>>ele;
    //     arr[ele]++;
    // }
    // while(arr.size()>0)
    // {

    // }

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

