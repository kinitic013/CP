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
bool checker(vi a,vi b,ll x)
{
    ll count=1;
    REP(i,0,a.size())
    {
        if(a[i]>=x-count && b[i]>=count-1)
        {
            count++;
        }
        if(count==x+1)
        {
            return true;
        }
    }
    return false;
}
void  solve()
{
    ll n;cin>>n;
    vi a(n);vi b(n);
    REP(i,0,n)
    {
        cin>>a[i]>>b[i];
    }

    ll l=1,r=n+1;
    ll temp=40;
    ll ans=l;
    while(temp--)
    {
        ll mid=(l+r)/2;
        bool check=checker(a,b,mid);
        if(check)
        {
            ans=max(ans,mid);
            l=mid;
        }
        else
        {
            r=mid;
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
