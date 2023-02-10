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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    int n;cin>>n;
    vi one;vi two;
    REP(i,0,n)
    {
        int ele;cin>>ele;
        if(i==0)
        one.pb(ele);
        else
        one.pb(one[i-1]+ele);
    }
    REP(i,0,n)
    {
        int ele;cin>>ele;
        if(i==0)
        two.pb(ele);
        else
        two.pb(two[i-1]+ele);
    }
    //   vector<vector<ll>> arr;arr.pb(one);arr.pb(two);
    ll result=LONG_LONG_MAX;
    REP(i,0,n)
    {
        ll val1=one[n-1]-one[i];
        ll val2;
        if(i==0)
        val2=0;
        else
        val2=two[i-1];
        result=min(result,max(val1,val2));
    }
    cout<<result;
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
