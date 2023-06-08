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
    ll q;cin>>q;
    map<ll,ll> arr;
    arr[0]=1;
    REP(i,0,q)
    {
        char state ;ll value;
        cin>>state>>value;
        if(state=='+')
        {
            arr.insert({value,1});
        }
        else
        {
            ll flag=0;
            ll curr=value;
            while(curr<=(ll)1e18)
            {
                auto it=arr.find(curr);
                if(it==arr.end())
                {
                    flag=1;
                    cout<<curr<<"\n";
                    break;
                }
                curr+=value;
            }
            if(flag==0)
            {
                cout<<(ll)(curr)<<"\n";
                continue;;
            }
        }
    }
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}

