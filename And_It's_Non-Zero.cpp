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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve(vector<vector<ll>> &arr)
{
    ll l,r;
    cin>>l>>r;
    //log2(100000)==18; 110000110101000000
    ll mini=LONG_LONG_MIN;
    REP(i,1,19)
    {
        mini=max(mini,arr[r][i]-arr[l-1][i]);
    }
    cout<<r-l+1-mini;
    return ;
}
int main()
{
    ll t;
    cin>>t;
    vector<vi> arr(200001,vector<ll>(19));
    REP(i,1,200001)
    {
        ll idx=1;
        ll x=i;
        while(x>0)
        {
            {
                arr[i][idx]=x%2+arr[i-1][idx];
            }
            idx++;
            x/=2;
        }
    }
    while(t--)
    {
        solve(arr);
        cout<<"\n";
    }
    return 0;
}