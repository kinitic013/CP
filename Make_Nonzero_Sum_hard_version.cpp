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
void  solve()
{
    ll n;cin>>n;
    vi arr(n);
    vector<pii> one;
    REP(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]==1)
        one.pb({i,1});
        else if(arr[i]==-1)
        one.pb({i,-1});
    }
    vector<pii> ans;
    ll m=one.size();
    if(m&1)
    {
        cout<<-1;
        return;
    }
    if(m==0)
    {
        cout<<1;
        cout<<endl;
        cout<<1<<" "<<n;
        cout<<endl;
        return;
    }
    if(one[0].ff!=0)
    {
        ans.pb({1,one[0].ff});
    }
    REP(i,0,m)
    {
        if(i!=0 && (one[i].ff-one[i-1].ff>=2))
        {
            ans.pb({one[i-1].ff+2,one[i].ff});
        }
        if(one[i+1].ff-one[i].ff==1)
        {
            if(one[i+1].ss==one[i].ss)
            {
                ans.pb({one[i].ff+1,one[i+1].ff+1});
            }
            else
            {
                ans.pb({one[i].ff+1,one[i].ff+1});
                ans.pb({one[i+1].ff+1,one[i+1].ff+1});
            }
            i++;
        }
        else
        {
            if(one[i+1].ss==one[i].ss)
            {
                if((one[i+1].ff-one[i].ff)&1)
                {
                    ans.pb({one[i].ff+1,one[i+1].ff+1});
                }
                else
                {
                    ans.pb({one[i].ff+1,one[i].ff+1});
                    ans.pb({one[i].ff+2,one[i+1].ff+1});
                }
            }
            else
            {
                if((one[i+1].ff-one[i].ff)%2==0)
                {
                    ans.pb({one[i].ff+1,one[i+1].ff+1});
                }
                else
                {
                    ans.pb({one[i].ff+1,one[i].ff+1});
                    ans.pb({one[i].ff+2,one[i+1].ff+1});
                }
            }
            i++;
        }
    }
    if(one[m-1].ff!=n-1)
    {
        ans.pb({one[m-1].ff+2,n});
    }
    cout<<ans.size()<<endl;
    REP(i,0,ans.size())
    {
        cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
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
        cout<<"\n";
    }
    return 0;
}

