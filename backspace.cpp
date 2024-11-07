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
    string arr,brr;
    cin>>arr>>brr;
    if(brr.size()>arr.size())
    {
        cout<<"NO";
        return;
    }
    ll i=arr.size()-1;
    ll j=brr.size()-1;
    while(i>=0 && j>=0)
    {
        if(arr[i]!=brr[j])
        {
            i-=2;
        }
        else
        {
            i--;
            j--;
        }
    }
    if(j==-1)
    {
        cout<<"YES";
    }
    else
    cout<<"NO";
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
