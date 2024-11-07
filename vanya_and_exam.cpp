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
#define vip vector<pii>
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll n,r,avg;cin>>n>>r>>avg;
    vip arr;
    ll sum=0;
    REP(i,0,n)
    {
        int ele1,ele2;cin>>ele1>>ele2;
        sum+=ele1;
        arr.pb({ele1,ele2});     
    }
    if(sum/n>=avg)
    {
        cout<<0;
        return;
    }
    sort(arr.begin(),arr.end(),cmps);
    ll count=0;
    sum=avg*n-sum;
    REP(i,0,n)
    {
        if(r-arr[i].ff>=sum)
        {
            count+=sum*arr[i].ss;
            break;
        }
        else
        {
            count+=(r-arr[i].ff)*arr[i].ss;
            sum-=(r-arr[i].ff);
        }
    }
    cout<<count;
    return;
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
