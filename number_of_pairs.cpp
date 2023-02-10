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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll n,l,r;cin>>n>>l>>r;input
    sort(arr.begin(),arr.end());ll count=0;
    REP(i,0,n)
    {
        if(arr[i]>(r/2)+1)
        {
            break;
        }
        ll l1=l-arr[i];
        ll r1=r-arr[i];
        auto it1=lower_bound(arr.begin()+i+1,arr.end(),l1);
        auto it2=upper_bound(arr.begin()+i+1,arr.end(),r1);
        {
            ll idx1=it1-arr.begin();
            ll idx2=it2-arr.begin()-1;
            if(it2==arr.end())
            {
                count+=n-idx1;
            }
            else
            {
                
                count+=idx2-idx1+1;
            }   
        }
    }
    cout<<count;
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
