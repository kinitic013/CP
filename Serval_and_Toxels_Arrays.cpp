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
#define mod (ll)998244353
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

ll power(ll x, ll y, ll p=(ll)(1e9+7))
{
    ll res = 1;  
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2    
        x = (x*x) % p;
    }
    return res;
}
void  solve()
{
    ll n,m;cin>>n>>m;
    vi arr(n+1); 
    arr.pb(-1);
    vi count(m+n+1,0);
    vector<pair<ll,bool>> state(m+n+1,{0,false});
    REP(i,1,n+1)
    {
        cin>>arr[i];
        state[arr[i]].ss=1;
    }
    REP(i,1,m+1)
    {
        ll pos,val;cin>>pos>>val;
        if(state[arr[pos]].ss)
        {
            state[arr[pos]].ss=0;
            count[arr[pos]]+=i-state[arr[pos]].ff;
            state[arr[pos]].ff=i;
        }
        arr[pos]=val;
        if(state[val].ss==false)
        {
            state[val].ss=true;
            state[val].ff=i;
        }
    }
    REP(i,1,m+n+1)
    {
        if(state[i].ss)
        {
            count[i]+=m-state[i].ff+1;
        }
    }
    ll array=m+1;
    ll ans=0;
    REP(i,1,m+n+1)
    {
        if(count[i]>1)
        {
            ans+=(count[i]*(m+1-count[i]));
            ans+=((count[i])*(count[i]-1))/2;
        }
        else if(count[i]==1)
        {
            ans+=m;
        }
    }
    cout<<ans;

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
