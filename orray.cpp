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
vi toBinary(ll n)
{
    vi ans(31,0);
    ll i=0;
    while(n)
    {
        if(n&1)
        ans[i]=1;

        n=n>>1;
        i++;
    }
    return ans;
}
void  solve()
{
    ll n;cin>>n;
    multiset<ll> arr;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        arr.insert(ele);
    }
    vi ans;
    ans.pb(*(--arr.end()));
    arr.erase((--arr.end()));
    ll res=ans[0];
    ll curr=res;
    ll len=log2(curr);
    vi temp=toBinary(curr);
    ll i=len;
    while(i>=0)
    {
        if(temp[i]==1)
        {
            i--;
            continue;
        }
        auto it=arr.begin();
        auto add=it;
        curr=res;
        ll flag=0;
        while(it!=arr.end())
        {
            ll val=(*it)|curr;
            if(val>=res)
            {
                flag=1;
                add=it;
                res=val;
            }
            it++;
        }
        if(flag==0)
        {
            break;
        }
        ans.pb(*add);
        arr.erase(add);
        temp=toBinary(res);
        i--;
    }
    auto it=arr.begin();
    while (it!=arr.end())
    {
        ans.pb(*it);
        it++;
    }
    REP(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    

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

