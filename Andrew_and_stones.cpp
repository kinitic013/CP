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
    ll n;
    cin>>n;
    vi arr;
    vi odd;
    bool flag=1;
    bool even=0;
    ll count=0;
    ll max_odd=0;
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        if(i!=0 && i!=n-1)
        {
            if(ele!=1)
            {
                flag=0;
            }
            if(ele%2==0)
            {
                count+=(ele/2);
                even=1;
            }
            else
            {
                //max_odd=max(max_odd,ele);
                count+=(ele/2)+1;
                odd.pb(i);
            }
            arr.pb(ele);
        }
    }
    if(n==3 && (arr[0]&1))// in size 3 middle element is odd
    {
        cout<<-1;
        return;
    }
    // if(max_odd<=3 && !even)// No even and maximum odd is 3 
    // {
    //     cout<<-1;
    //     return;
    // }
    if(flag)// if all found
    {
        cout<<-1;
        return;
    }
    even=0;
    bool end_even=0;
    ll size=0;
    REP(i,0,n-2)
    {
        if(!arr[i]&1)
        {
            if(even)
            {
                end_even=1;
            }
            even=1;
            continue;
        }
        if(even && !end_even)
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