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
// ll sqrtt(ll n)
// {
//     if(n==1)
//     {
//         return 1;
//     }
//     ll l=1,h=n-1,mid;
//     while(h-l>1)
//     {
//         mid=(l+h)/2;
//         if(mid*mid>n)
//         {
//             h=mid;
//         }
//         else 
//         {
//             l=mid;
//         }
//     }
//     return l;
// }
void  solve()
{
    ll l,r;cin>>l>>r;
    ll count=0;
    ll i,j;
    i=(ll)sqrt(l);
    j=(ll)sqrt(r);
    if(i*i==l)// (ixxxxxxxxxxxx)jxxxxxxx
    {
        count=3*(j-i);
    }
    else// xxxxxx(ixxxxxxxxxxxxx)jxxxxxxx
    {
        count=3*(j-(i+1));
        //(xxxxxx)ixxxxxxxxxxxxxjxxxxxxx
        if(i*(i+1)>=l)
        {
            count++;
        }
        if(i*(i+2)>=l)
        {
            count++;
        }
    }
    //xxxxxxixxxxxxxxxxxxx(jxxxxxxx)
    count++;//adding jth 
    if((j+1)*j<=r)
    {
        count++;
        if((j+2)*(j)<=r)
        {
            count++;
        }
    }
    cout<<count;
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
