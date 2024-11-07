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
    ll n,s;cin>>n>>s;
    vi arr(n);

    REP(i,0,n)
    {
        cin>>arr[i];
    }
    ll mini=*min_element(arr.begin(),arr.end());
    ll maxi=*max_element(arr.begin(),arr.end());
    vi suffix(maxi+2,0);
    REP(i,0,n)
    {
        suffix[arr[i]]++;
    }
    for(int i=maxi;i>=mini;i--)
    {
        suffix[i]+=suffix[i+1];
    }
    ll curr=0,count=0;
    ll i=maxi;
    while(i>=mini)
    {
        if(curr+suffix[i]>s)
        {
            count++;
            curr=0;
        }
        curr+=suffix[i];
        i--;
    }
    if(curr!=n)
    count++;
    cout<<count;
}
int main()
{
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
