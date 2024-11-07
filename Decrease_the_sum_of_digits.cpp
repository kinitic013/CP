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

void  solve()
{
    ll n,s;cin>>n>>s;
    vi arr(20);
    ll temp=n;
    ll sum=0;
    ll i=0;
    while(temp)
    {
        arr[i]=(temp%10);
        sum+=temp%10;
        temp/=10;
        i++;
    }
    if(sum<=s)
    {
        cout<<0;
        return;
    }
    ll curr=-1;
    i=0;
    while(curr<sum-s)
    {
        curr+=arr[i];
        arr[i]=0;
        i++;
    }
    arr[i]++;
    while(arr[i]>9)
    {
        arr[i]=0;
        arr[i+1]++;
        i++;
    }
    ll multi=1;
    ll result=0;
    REP(i,0,20)
    {
        result+=(multi*(arr[i]));
        multi*=10;
    }
    cout<<result-n;
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
