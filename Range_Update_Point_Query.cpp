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
ll sum(ll n)
{
    ll ele=0;
    while(n)
    {
        ele+=n%10;
        n=n/10;
    }
    return ele;
}
void  solve()
{
    ll n,q;cin>>n>>q;
    vi arr(n);
    map<ll,ll> m;
    REP(i,0,n) 
    {
        cin>>arr[i];
        m[i]=0;
    }
    vector<vector<ll>> mat(n);

    REP(i,0,n)
    {
        ll ele=arr[i];
        ll c=2;
        mat[i].pb(ele);
        while(c--)
        {
            ll val=sum(ele);
            ele=val;
            mat[i].pb(ele);
        }
    }
    REP(i,0,q)
    {
        ll state;
        cin>>state;
        if(state==1)
        {
            ll l,r;cin>>l>>r;
            l--;
            r--;
            auto start=m.lower_bound(l);
            auto end=m.upper_bound(r);
            if(start==m.end())
            continue;
            while(start!=end)
            {
                start->ss++;
                if(start->ss>=3)
                {
                    auto it=start;
                    start++;
                    m.erase(it);
                }
                else
                {
                    arr[start->ff]=mat[start->ff][start->ss];
                    start++;
                }

            }
        }
        else
        {
            ll x;cin>>x;
            x--;
            cout<<arr[x]<<endl;
        }
    }
    return;

}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        // cout<<"\n";
    }
    return 0;
}
