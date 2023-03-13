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
    ll n,k;cin>>n>>k;
    vector<pii> arr;
    REP(i,0,n)
    {
        ll ele1,ele2;
        cin>>ele1>>ele2;
        if(k<=ele2 && k>=ele1)
        {
            arr.pb({ele1,ele2});
        }
    }
    vi counter(51,0);
    REP(i,1,51)
    {
        REP(j,0,arr.size())
        {
            if(i<=arr[j].ss && i>=arr[j].ff)
            {
                counter[i]++;
            }
        }
    }
    REP(i,1,51)
    {
        if(counter[i]>=counter[k] && i!=k)
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
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
