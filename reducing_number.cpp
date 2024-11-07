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
struct sq
{
    vi div;
    ll len;
    vi idx;
};


void  solve()
{
    string arr;
    cin>>arr;
    ll k;cin>>k;
    ll n=arr.size();
    vector<vi > m(10);
    {
        REP(i,0,n)
        {
            m[arr[i]-'0'].pb(i);
        }
    }
    string ans;
    ll l=0;
    ll size=n-k;
    ll flag=1;
    while(size>0)
    {
        ll r=n-size;
        REP(i,0,10)
        {
            if(flag && i==0)
            {
                flag=0;
                continue;
            }
            auto it=lower_bound(m[i].begin(),m[i].end(),l);
            if(it==m[i].end())//not fount
            continue;
            else
            {
                if(*it>=l && *it<=r)
                {
                    ans.pb(arr[*it]);
                    l=*it+1;
                    size--;
                    break;
                }   
                else
                continue;
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

