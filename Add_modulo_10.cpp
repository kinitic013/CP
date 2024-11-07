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
    int n;cin>>n;
    vi arr(n);ll idx=0;
    ll maxi=0;
    REP(i,0,n) 
    {
        cin>>arr[i];
        while(arr[i]%10!=0 && arr[i]%10!=2)
        {
            arr[i]+=arr[i]%10;
        }
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            idx=i;
        }
        
    }
    ll dig=maxi%10;
    REP(i,0,n)
    {
        if((arr[i]%10==0 && maxi!=arr[i]))
        {
            cout<<"No";
            return;
        }
        if(maxi%10==0)
        {
            if(arr[i]%10==5 && (arr[i]+5)!=maxi)
            {
                cout<<"No";
                return;
            }
        }
        ll val=(maxi-arr[i])/20;
        arr[i]+=(val*20);
        ll counter=5; bool flag=0;
        while(--counter)
        {
            if(arr[i]==maxi)
            {
                flag=1;
                break;
            }
            arr[i]+=(arr[i]%10);
        }
        if(!flag)
        {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
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

