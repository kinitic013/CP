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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,k;cin>>n>>k;
    multimap<ll,ll> arr;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        arr.insert({ele%k,ele});
    }
    ll count=0;
    while(!arr.empty())
    {
        auto it1=--arr.end();
        auto it2=arr.lower_bound(k-it1->ff);
        if(it2==it1 || it2==arr.end())
        {
            break;
        }
        count+=(it1->ss+it2->ss)/k;
        arr.erase(it1);
        arr.erase(it2);
    }
    if(!arr.empty())
    {
        auto it=arr.begin();
        while(it!=arr.end())
        {
            ll val1=it->ss;
            it++;
            ll val2=it->ss;
            count+=(val1+val2)/k;
            it++;
        }
        
    }
    cout<<count;
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
