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
    int a,b;cin>>a>>b;
    int t,d;cin>>t>>d;
    vi arr(t);
    arr[t-1]=b;
    arr[0]=a;
    ll i=t-2;
    ll sum=arr[0]+arr[t-1];
    //form right to the peak
    while(i>0)
    {
        ll ele=arr[i+1]+d;
        if(ele-arr[0]<=d*i)
        {
            arr[i]=ele;
            sum+=ele;
            i--;
            continue;
        }
        else
        break;
    }
    ll j=1;
    while(j<=i)
    {
        arr[j]=d+arr[j-1];
        sum+=arr[j];
        j++;
    }
    cout<<sum;
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
