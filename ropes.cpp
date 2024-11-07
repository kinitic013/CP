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
bool checker(vector<double> arr,double mid,ll k)
{
    ll val=0;
    REP(i,0,arr.size())
    {
        val+=(arr[i]/mid);
    }
    if(val>=k)
    return true;
    else 
    return false;
}

void  solve()
{
    ll n,k;cin>>n>>k;
    vector<double> arr(n);
    double maxi=0;
    REP(i,0,n)
    {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    double l=0;double r=maxi+1;
    double ans=l;
    while(r-l>=(double)1e-6)
    {
        double mid=(double)(r+l)/2;
        if(checker(arr,mid,k))
        {
            ans=max(ans,mid);
            l=mid+1e-6;
        }
        else
        {
            r=mid-1e-6;
        }
    }
     cout << fixed << setprecision(18) << ans << endl;
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
