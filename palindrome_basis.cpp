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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool IntegerpCheck(ll n)
{
    string arr=to_string(n);
    ll i=0;ll j=arr.size()-1;
    while(i<=j)
    {
        if(arr[i]!=arr[j])
        return false;
        i++;j--;
    }
    return true;
}


void  solve(vi &p,vi &ans)
{
    ll n;cin>>n;
    cout<<ans[n];
    return;
}

int main()
{
    vi p;
    REP(i,1,40001)
    {
        if(IntegerpCheck(i))
        p.pb(i);
    }
    ll n=40001;
    vi ans(n+1,0);
    ans[0]=1;
    REP(i,0,p.size())//choosing coin
    {
        if(p[i]>n)
        {
            break;
        }
        REP(j,1,n+1)
        {
            if(j-p[i]>=0)
            {
                ans[j]=(ans[j]+ans[j-p[i]])%MOD;
            }            
        }
    }

    ll t;
    cin>>t;
    while(t--)
    {
        solve(p,ans);
        cout<<"\n";
    }
    return 0;
}
