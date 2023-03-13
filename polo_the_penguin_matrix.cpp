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

ll checker(vi arr,ll x1,ll d)
{
    ll coun=0;
    REP(i,0,arr.size())
    {
        coun+=((abs(arr[i]-x1))/d);
    }
    return coun;
}
void  solve()
{
    ll n,m,d;cin>>n>>m>>d;
    bool no=0;
    vi arr;
    REP(i,0,n*m)
    {
        ll ele;cin>>ele;
        arr.pb(ele);
        if(i!=0)
        {
            if(arr[0]%d!=arr[i]%d)
            {
                no=1;
            }
        }
    }
    sort(arr.begin(),arr.end());
    if(no)
    {
        cout<<-1;
        return;
    }
    for(int i=arr.size()-1;i>=0;i--)
    {
        arr[i]=arr[i]-arr[0];
    }
    ll l=0; ll r=arr[n*m-1];
    while((r-l)/d>=3)
    {
        ll x1=l+(r-l)/3;
        ll rem1=(x1%d);
        if(x1%d!=0)
        {
            x1-=(x1%d);
        }
        ll x2=l+(2*(r-l))/3;
        ll rem2=(x2%d);
        if(x2%d!=0)
        {
            x2-=(x2%d);
        }
        ll val1=checker(arr,x1,d);
        ll val2=checker(arr,x2,d);
        if(val1>=val2)
        {
            l=x1;
        }
        else
        {
            r=x2;
        }
    }
    ll ans=min(checker(arr,l,d),min(checker(arr,l+d,d),checker(arr,l+(2*d),d)));
    cout<<ans;
}
int main()
{

    {
        solve();
        cout<<"\n";
    }
    return 0;
}
