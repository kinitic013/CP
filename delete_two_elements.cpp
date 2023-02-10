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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
ll helper(map<ll,ll> &arr,ll sum)
{
    ll count=0;
    auto it=arr.begin();
    if(sum&1)
    {
        while(it->ff<=sum/2 && it!=arr.end())
        {
            auto add=arr.find(sum-it->ff);
            if(add!=arr.end())//element found
            {
                count+=(it->ss*add->ss);
            }
        it++;
        }
    }
    else
    {
         while(it->ff<sum/2 && it!=arr.end())
        {
            auto add=arr.find(sum-it->ff);
            if(add!=arr.end())//element found
            {
                count+=(it->ss*add->ss);
            }
        it++;
        }
        {
            auto add=arr.find(sum/2);
            if(add!=arr.end())
            count+=(add->ss*(add->ss-1))/2;
        }
        
    }
    
    // if(sum%2==0)
    // {
    //     auto add=arr.find(sum/2);
    //     if(add!=arr.end())
    //     count+=(add->ss*(add->ss-1))/2;
    // }
    // else
    // {
    //     auto add=arr.find(sum/2+1);
    //     if(add!=arr.end())
    //     count+=(add->ss*(it->ss));
    // }
    return count;
}
void  solve()
{
    ll n;
    cin>>n;
    map<ll,ll> arr;
    ll sum=0;
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        sum+=ele;
        arr[ele]++;
    }   
    ll mean=sum/n;
    ll rem=sum%n;
    ll val=0;

    if(rem==0)
    {
        val=helper(arr,2*mean);
    }
    else if(n%rem==0 && n/rem==2)// extra 0.5
    {
        val=helper(arr,2*mean+1);
    }
    else
    {
        cout<<0;
        return;
    }
    cout<<val;
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