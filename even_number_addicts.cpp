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
    ll n;cin>>n;
    vi arr(n);
    ll odd=0,even=0;
    REP(i,0,n) 
    {
        cin>>arr[i];
        if(arr[i]&1) odd++;
        else 
        even++;
    }
    ll need=(odd+even)/2 +(odd+even)%2;
    ll o=0,e=need;
    ll counter=o+e;
    while(counter--)
    {
        if(e<=(even/2+ even%2) && o<=(odd/2+odd%2))
        {
            cout<<"Alice";
            return;
        }
        e-=2;
        o+=2;
        if(e<0 || o>need)
        {
            break;
        }
    }
    cout<<"Bob";
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

