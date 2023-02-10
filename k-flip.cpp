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
    int n,k;cin>>n>>k;
    string arr;cin>>arr;
    vi prefix(n,0);
    // REP(i,0,n-k)
    // {
    //     if(i==0)
    //     {
    //         if(arr[i]=='1')
    //         {
    //             prefix[i]=1;
    //             arr[i]='0';
    //         }
    //         continue;
    //     }
    //     if(prefix[i-1]%2!=0)//flip value
    //     {
    //         if(arr[i]=='1')
    //         arr[i]='0';
    //         else
    //         arr[i]='1';
            
    //     }
    //     else
    //     prefix[i]=prefix[i-1];

    //     if(arr[i]=='1')
    //     {
    //         prefix[i]=prefix[i-1]+1;
    //         arr[i]='0';
    //     }
    //     else
    //     {
    //         prefix[i]=prefix[i-1];
    //     }
    // }
    REP(i,0,n)
    {
        if(i==0)
        {
            if(arr[i]=='1')
            {
                prefix[i]=1;
                arr[i]='0';
            }
            continue;
        }
        ll idx=i-k;
        if(idx<0)
        {
            if((prefix[i-1])%2!=0)//flip value
            {
                if(arr[i]=='1')
                arr[i]='0';
                else
                arr[i]='1';

            }
        }
        else
        {
            if((prefix[i-1]-prefix[i-k])%2!=0)//flip value
            {
                if(arr[i]=='1')
                arr[i]='0';
                else
                arr[i]='1';

            }
        }
        
        if(i<(n-k+1) && arr[i]=='1')
        {
            prefix[i]=prefix[i-1]+1;
            arr[i]='0';
        }
        else
        {
            prefix[i]=prefix[i-1];
        }
    }
    cout<<arr;
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
