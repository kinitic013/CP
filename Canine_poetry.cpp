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
string alpha="abcdefghijklmnopqrstuvwxyz";
void  solve()
{
    string arr;cin>>arr;int n=arr.size();
    ll count=0;
    vi done(n,0);
    if(arr[0]==arr[1])
    {
        count++;
        done[1]=1;
    }
    REP(i,1,n-1)
    {
        if(arr[i-1]==arr[i+1] && done[i+1]==0 && done[i-1]==0)
        {
            count++;
            done[i+1]=1;
            continue;
        }
        else if(arr[i]==arr[i+1] && done[i]==0 && done[i+1]==0)
        {
            count++;
            done[i+1]=1;
            continue;
        }
    }
    cout<<count;
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
