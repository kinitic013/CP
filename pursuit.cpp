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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;
    cin>>n;
    vi a,b;
    ll suma=0;ll sumb=0;
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        suma+=ele;
        a.pb(ele);
    }
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        sumb+=ele;
        b.pb(ele);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll i=(n/4);
    ll j=i;
    REP(m,0,i)
    {
        suma-=a[m];
        sumb-=b[m];
    }
    ll count=0;
    if(suma>=sumb)
    {
        cout<<0;
        return;
    }
    while(suma<sumb)
    {
        //a
        suma+=100;
        if((n+1)/4!=(n/4))
        {
            suma-=a[i];
            i++;
        }

        //b
        if((n+1)/4!=(n/4))
        {
            
        }
        else
        {
            if(j>0)
            {
                j--;
                sumb+=b[j];
            }
        }
        n++;
        count++;
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