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
bool check(vi arr,ll k,ll c,ll d)
{
    ll n=arr.size();
    ll dino=arr[min((ll)k,(ll)arr.size()-1)];
    ll days=c/dino;
    days*=(k+1);
    if(c%dino==0)
    {
        days-=max((ll)0,k+1-n);
    }
    if(c%dino!=0)
    {
        auto it=lower_bound(arr.begin(),arr.end(),c%dino);
        days+=it-arr.begin()+1;
    }
 
    if(days>d)
    return false;
    else
    return true;
}
// bool check(vi arr,ll k,ll c,ll d)
// {
//     ll n=arr.size();
//     ll dino=arr[min((ll)k,(ll)arr.size()-1)];
//     ll days=c/dino;
//     days--;
//     days*=(k+1);
//     days+=min(k+1,n);
//     if(c%dino!=0)
//     {
//         auto it=lower_bound(arr.begin(),arr.begin()+min(k+1,n),c%dino);
//         days+=it-arr.begin()+1;
//     }

//     if(days>d)
//     return false;
//     else
//     return true;
// }
void  solve()
{
    ll n,c,d;
    cin>>n>>c>>d;
    vi arr(n);
    vi pre(n);
    ll sum=0;
    REP(i,0,n) 
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<ll>());
    REP(i,0,n)
    {
        sum+=arr[i];
        pre[i]=sum;
        if(pre[i]>=c && i+1<=d)
        {
            cout<<"Infinity";
            return;
        }
    }
    ll ext=0;
    if(c%arr[0]!=0)
    ext++;
    if((c/arr[0])+ext>d)
    {
        cout<<"Impossible";
        return;
    }

    ll counter=40;
    ll l=0; ll h=d+1;
    ll k=(l+h)/2;
    while(counter--)
    {
        k=(l+h)/2;
        bool flag=check(pre,k,c,d);
        if(flag)
        {
            l=k;
        }
        else
        {
            h=k;
        }
    }
    if(check(arr,h,c,d))
    {
        cout<<h;
        return;
    }
    cout<<l;
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

