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
ll log_a_to_base_b(ll a, ll b)
{
    return log2(a) / log2(b);
}
pii two_and_five(ll a)
{
    pii ans={0,0};
    while(a%2==0)
    {
        ans.ff++;
        a/=2;
    }
    while(a%5==0)
    {
        ans.ss++;
        a/=5;
    }
    return ans;
}
void  solve()
{
    ll n,m;cin>>n>>m;
    ll count=0;
    pii num=two_and_five(n);
    pii multi=two_and_five(m);
    ll val=1;
    count+=min(num.ff,num.ss);
    num.ff-=count;num.ss-=count;
    while(num.ss>0)
    {
        if(val*2<=m)
        {
            val*=2;
            count++;
            num.ss--;
        }   
        else
        break;
    }
    while(num.ff>0)
    {
        if(val*5<=m)
        {
            val*=5;
            count++;
            num.ff--;
        }   
        else
        break;
    }
    while(val<=m)
    {
        if(val*10<=m)
        {
            val*=10;count++;
        }   
        else
        break;
    } 
    val*=(m/val);
    if(val==1)
    {
        val=m;
    }
    cout<<n*val;
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
