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
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;
    cin>>n;
    input
    map<ll,ll > arr;
    bool flag=true;
    REP(i,0,n)
    {
        arr[list[i]]++;
    }
    if(arr.size()==1)
    {
        cout<<0;
        return;
    }
    ll count=1;
    ll i=n-1;
    vi sorted;
    REP(i,0,n-1)
    {
        if(list[i]>list[i+1])
        {
            flag=false;
        }
    }
    if(flag)//when array is already sorted
    {
        cout<<0;
        return;
    }
    for(;i>0;i--)
    {
        if(list[i-1]==list[i])//in right order
        {
            count++;
        }
        else if(list[i-1]<list[i])
        {
            if(count!=arr[list[i]])
            {
                break;
            }
            else
            {
                sorted.pb(list[i]);
                count=1;
            }
        }
        else
        {
            if(count==arr[list[i]])
            sorted.pb(list[i]);

            break;
        }

    }
    cout<<arr.size()-sorted.size();
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