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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
bool checker(vi arr,ll mid)
{
    ll count=0;
    ll one=arr[0]+(2*mid);
    auto it2=upper_bound(all(arr),one);
    if(it2==arr.end())
    return true;

    ll two=*it2+(2*mid);
    
    auto it3=upper_bound(all(arr),two);
    if(it3==arr.end())
    return true;

    ll three=*it3+(2*mid);

    if(three<arr[arr.size()-1])
    return false;
    else
    return true;
}
void  solve()
{
    ll n;cin>>n;
    ll mini=LONG_LONG_MAX;
    ll maxi=LONG_LONG_MIN;
    vi arr(n); REP(i,0,n)
    {
        cin>>arr[i];
        mini=min(arr[i],mini);
        maxi=max(arr[i],maxi);
    }
    sort(all(arr));

    ll l=0;
    ll r=maxi-mini;
    ll counter=40;
    while(counter--)
    {
        ll mid=(l+r)/2;
        bool check=checker(arr,mid);
        if(check)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    cout<<r;
    return;
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
