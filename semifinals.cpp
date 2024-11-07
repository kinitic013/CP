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
    int n;cin>>n;
    vector<pair<ll,pair<ll,ll>>> arr; // value,(type,idx)
    REP(i,0,n)
    {
        int ele;cin>>ele;
        arr.pb({ele,{0,i}});
        cin>>ele;
        arr.pb({ele,{1,i}});
    }
    sort(arr.begin(),arr.end());
    string a,b;
    REP(i,0,n/2)
    {
        a.pb('1');
        b.pb('1');
    }
    REP(i,(n/2),n)
    {
        a.pb('0');
        b.pb('0');
    }
    REP(i,0,n)
    {
        if(arr[i].ss.ff==0)
        a[arr[i].ss.ss]='1';
        else
        b[arr[i].ss.ss]='1';
    }
    cout<<a<<endl<<b;
    return;
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
