#include<bits/stdc++.h>
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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    string arr;
    cin>>arr;
    ll zero=0;ll one=0;
    REP(i,0,n)
    {
        if(arr[i]=='1')
        {
            one++;
        }
        else
        zero++;
    }
    if(zero==0)
    {
        cout<<"DRAW";
        return;
    }
    if(zero==1)
    {
        cout<<"BOB";
        return;
    }
    if(zero&1)// odd
    {
        cout<<"ALICE";
        return;
    }
    else //zero even
    {
        cout<<"BOB";
        return;
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