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
bool cal(vi arr,int d,int c,int k)
{
    ll val=0;
    int n=arr.size();
    ll day=0;
    bool flag=0;
    while(day<d)
    {
        REP(i,0,min(n,k))
        {
            val+=arr[i];
            day++;
            if(val>=c)
            {
                return true;
            }
            if(day==d)
            {
                flag=1;
                break;
            }
        }
        day+=min(n,k);
        if(flag)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {

    }
}
void  solve()
{
    ll n,c,d;cin>>n>>c>>d;input
    sort(arr.begin(),arr.end(),greater<ll>());
    ll
    cal(arr,d,c,k);
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
