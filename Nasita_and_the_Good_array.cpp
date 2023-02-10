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
    int n;cin>>n;input
    ll idx=0;
    ll mini=LONG_LONG_MAX;
    REP(i,0,n)
    {
        if(arr[i]<mini)
        {
            mini=arr[i];
            idx=i;
        }
    }
    vector<vector<ll>> result;
    REP(i,0,n)
    {
        if(i!=idx)
        {
            vi temp;
            temp.pb(idx+1);temp.pb(i+1);temp.pb(arr[idx]);temp.pb(arr[idx]+abs(i-idx));
            result.pb(temp);
        }
    }
    cout<<result.size()<<endl;
    REP(i,0,result.size())
    {
        REP(j,0,4)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
