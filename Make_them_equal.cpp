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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}

//     REP(i,0,n)
//     {
//         ll ele;
//         cin>>ele;
//         x.pb(ele);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n;
    char a;string arr;
    cin>>n>>a>>arr;
    bool left=0,right=0;
    REP(i,0,n-1)
    {
        if(arr[i]!=a)
        {
            left=1;
            break;
        }
    }
    if(!left && arr[n-1]==a)//whole array aaaaaaaaaa
    {
        cout<<0;
        return;
    }
    else if(!left && arr[n-1]!=a)// left all aaaaaaaaaaaab
    {
        cout<<1<<'\n'<<n-1;
        return;
    }
    else if(arr[n-1]==a)
    {
        cout<<1<<'\n'<<n;
        return;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==a)
        {
            if(2*(i+1)>n)
            {
                cout<<1<<endl;
                cout<<i+1;
                return;
            }
            else
            {
                cout<<2<<endl;
                cout<<n-1<<" "<<n;
                return;
                
            }
        }
    }
    cout<<2<<endl;
    cout<<n-1<<" "<<n;
    return ;
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