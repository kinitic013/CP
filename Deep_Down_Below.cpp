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
    if(a.ff!=b.ff)
    return a.ff<b.ff;
    else
    return a.ss>b.ss;
}

void  solve()
{
    ll n;cin>>n;
    vector<pii> arr;
    REP(i,0,n)
    {
        ll k;cin>>k;
        vi temp;
        ll maxi=0;ll val=0;
        ll idx=-1;
        REP(j,0,k)
        {
            ll ele;cin>>ele;
            temp.pb(ele);
            if(j==0)
            {
                maxi=ele+1;
                val=maxi;
                maxi++;
            }
            else
            {
                if(maxi<=ele)
                {
                    val=ele+1-j;
                    maxi=val+j;
                    maxi++;
                }
                else
                maxi++;
            }
        }
        arr.pb({val,k});
    }
    sort(arr.begin(),arr.end(),cmps);
    ll val=arr[0].ff;
    ll maxi=val;
    ll sum=arr[0].ss;
    REP(i,1,arr.size())
    {
        if(val+sum<arr[i].ff)
        {
            val+=arr[i].ff-(sum+val);
            maxi=arr[i].ff+1;
        }
        else
        {
            maxi+=arr[i].ss;
        }
        sum+=arr[i].ss;
    }
    cout<<val;

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
