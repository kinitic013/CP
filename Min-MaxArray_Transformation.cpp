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
    int n;cin>>n;
    vi a(n),b(n);
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) cin>>b[i];
    vi mi(n),ma(n);
    vi above(n);
    ll maxi=b[n-1];
    for(int i=n-1;i>=0;i--)
    {
        auto add=lower_bound(b.begin(),b.end(),a[i]);
        if(add==b.end())
        {
            above[i]=-1;
        }
        else
        above[i]=add-b.begin();
    }
    ll j=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(above[i]==-1)
        {
            REP(j,0,n)
            {
                mi[j]=0;
                ma[j]=0;
            }
            break;
        }

        ma[i]=maxi-a[i];
        mi[i]=b[above[i]]-a[i];
        if(above[i]==i)
        {
            if(i!=0)
            maxi=b[i-1];
            else
            {
                break;
            }
        }
    }
    REP(i,0,n) cout<<mi[i]<<" ";
    cout<<endl;
    REP(i,0,n) cout<<ma[i]<<" ";

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
