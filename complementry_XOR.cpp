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
void  solve()
{
    ll n;string a,b;cin>>n>>a>>b;
    vector<pii> result;
    bool equal=(a[0]==b[0]);
    if(a[0]==b[0])
    {
        REP(i,0,n)
        {
            if(a[i]!=b[i])
            {
                cout<<"NO";
                return;
            }
        }
    }
    else
    {
        REP(i,0,n)
        {
            if(a[i]==b[i])
            {
                cout<<"NO";
                return;
            }
        }
    }
    //if yes than continue
    bool flag=0;ll idx=0;bool done=0;
    for(ll k=0;k<n;k++)
    {
        if(a[k]=='1')
        {
            ll idx=n-k;
            result.pb({k+1,k+1});
            equal=!equal;
        }
    }
    if(!equal)
    {
        result.pb({1,1});
        result.pb({2,n});
        result.pb({1,n});
    }
    
    cout<<"YES"<<endl;
    cout<<result.size()<<endl;
    REP(i,0,result.size())
    {
        cout<<result[i].ff<<" "<<result[i].ss<<endl;
    }
    return ;
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