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
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll n,q;cin>>n>>q;
    vi arr(n);
    ll id=0;
    REP(i,0,n){cin>>arr[i]; if(arr[i]==n){id=i;}} 
    ll maxi=max(arr[0],arr[1]);
    vi m;m.pb(maxi);
    REP(i,1,n)
    {
        m.pb(max(m[i-1],arr[i]));
    }
    REP(i,0,q)
    {
        ll idx,k;cin>>idx>>k;
        idx--;
        if(k<idx-1)
        {
            cout<<0<<endl;
            continue;
        }
        if(m[idx]!=arr[idx])
        {
            cout<<0<<endl;
            continue;
        }
        if(id==idx)
        {
            if(id==0)
            {
                cout<<k<<endl;
            }
            else
            cout<<k-id+1<<endl;
            continue;
        }
        auto add=upper_bound(m.begin(),m.end(),arr[idx]);
        add--;
        ll val1=add-m.begin();
        auto it=lower_bound(m.begin(),m.end(),arr[idx]);
        ll val2=it-m.begin();
        if(it==m.begin())
        {

        }
        else
        val2--;
        ll val=min(val1,k)-val2;
        cout<<val<<endl;

        continue;
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();

    }
    return 0;
}
