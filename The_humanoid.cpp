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
    ll n,h;cin>>n>>h;
    ll temp=h;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());
    vi pre(n);
    pre[0]=arr[0]/2;
    REP(i,1,n)
    {
        pre[i]=pre[i-1]+arr[i]/2;
    }
    ll g=2,b=1;
    ll count=0;
    REP(i,0,n)
    {
        if(h>arr[i])
        {
            h+=arr[i]/2;
            count++;
        }
        else
        {
            if(b==1)
            {
                h*=3;
                b--;
                i--;
                continue;
            }
            if(g>=1)
            {
                g--;
                h*=2;
                i--;
                continue;
            }

            break;
        }
    }
    ll count2=0;
    b=1;
    g=2;
    h=temp;
    REP(i,0,n)
    {
        if(h>arr[i])
        {
            h+=arr[i]/2;
            count2++;
        }
        else
        {

            if(g>=1)
            {
                g--;
                h*=2;
                i--;
                continue;
            }
            if(b==1)
            {
                h*=3;
                b--;
                i--;
                continue;
            }

            break;
        }
    }
    ll count3=0;
    h=temp;
    b=1;g=2;
    REP(i,0,n)
    {
        if(h>arr[i])
        {
            h+=arr[i]/2;
            count3++;
        }
        else
        {

            if(g==2)
            {
                g--;
                h*=2;
                i--;
                continue;
            }
            if(b==1)
            {
                h*=3;
                b--;
                i--;
                continue;
            }
            if(g==1)
            {
                g--;
                h*=2;
                i--;
                continue;
            }

            break;
        }
    }

    cout<<max(count,max(count3,count2));
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

