#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
vector<pii> Divisors(ll n)
{
    vector<pii>ans;
    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, prll only one
            if (n/i == i)
                ans.pb({i,i});
            else
            {
                ans.pb({i,n/i});
            }     
        }
    }
    return ans;
}

void  solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x=a+1;
    while(x<=c)
    {
        ll val=__gcd(x,a*b);
        ll y=(a*b)/val;
        if(b/y!=d/y)
        {
            cout<<x<<" "<<y*(d/y);
            return;
        }
        x++;
    }
    // x=b+1;
    // while(x<=d)
    // {
    //     ll val=__gcd(x,a*b);
    //     ll y=(a*b)/val;
    //     if(y>a && y<=c)
    //     {
    //         cout<<x<<" "<<y;
    //         return;
    //     }
    //     x++;
    // }
    cout<<-1<<" "<<-1;
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

    // vi temp_ac(arr.size(),0);
    // vi temp_bd(arr.size(),0);
    // vi bd(arr.size(),0);
    // ll n=arr.size();
    // vi ac(arr.size(),0);
    // REP(i,0,arr.size())
    // { 
    //     if(arr[i].ss<=c && arr[i].ss>a)// in temp_ac
    //     {
    //         temp_ac[i]=1;
    //     }
    //     if(arr[i].ss<=d && arr[i].ss>b)// in temp_bd
    //     {
    //         temp_bd[i]=1;
    //     }
    // }
    // ac[0]=temp_ac[0];
    // bd[0]=temp_bd[0];
    // REP(i,1,arr.size())
    // {
    //     if(temp_ac[i]==1)
    //     {
    //         ac[i]=ac[i-1]+1;
    //     }
    //     else
    //     ac[i]=ac[i-1];

    //     if(temp_bd[i]==1)
    //     {
    //         bd[i]=bd[i-1]+1;
    //     }
    //     else
    //     bd[i]=bd[i-1];
    // }
    // ll idx=-1;
    // ll i=0;
    // ll flag=0;
    // for(;i<n;i++)
    // {
    //     if(arr[i].ff<=c && arr[i].ff>a)// in ac
    //     {
    //         if(bd[i]>0)
    //         {
    //             idx=i;
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(arr[i].ff<=d && arr[i].ff>b)// in bd
    //     {
    //         if(ac[i]>0)
    //         {
    //             idx=i;
    //             flag=2;
    //             break;
    //         }
    //     }
    // }
    // REP(j,0,n)
    // {
    //     if(temp_ac[j]==1 && temp_bd[j]==1)
    //     {
    //         cout<<arr[j].ss<<" "<<arr[j].ss;
    //         return;
    //     }
    // }
    // if(idx==-1)
    // {
    //     cout<<-1<<" "<<-1;
    //     return;
    // }
    // else
    // {
    //     {
    //         REP(j,0,idx+1)
    //         {
    //             if(flag==1 && temp_bd[j]==1)
    //             {
    //                 cout<<arr[i].ff<<" "<<arr[j].ss;
    //                 return;
    //             }
    //             if(flag==2 && temp_ac[j]==1)
    //             {
    //                 cout<<arr[i].ff<<" "<<arr[j].ss;
    //                 return;
    //             }
    //         }
    //     }
    // }