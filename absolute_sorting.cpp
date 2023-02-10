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
    ll n;cin>>n;
    vi arr(n);
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        if(i!=0)
        {
            if(ele==arr[i-1])
            {
                continue;
            }
        }
        else
        {
            arr[i]=ele;
        }
    }
    if(arr.size()==1)
    {
        cout<<0;
        return;
    }
    ll mini=0;ll maxi=(ll)(1e9);
    REP(i,0,n-1)
    {
        
    }
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
