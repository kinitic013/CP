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

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    multiset<ll> arr;
    ll sum=0;
    REP(i,0,n+2)
    {
        ll ele;
        cin>>ele;
        sum+=ele;
        arr.insert(ele);
    }
    ll last=*(--arr.end());
    ll slast=*(--(--arr.end()));
    if(sum-last-slast==slast)
    {
        auto it=arr.begin();
        auto end=arr.end();
        end--;end--;
        while(it!=end)
        {
            cout<<*it<<" ";
            it++;
        }
        return;
    }
    else if(sum-last-slast>last)
    {
        cout<<-1;
        return;
    }
    ll val=sum-2*last;
    if(val<=0)
    {
        cout<<-1;
        return;
    }
    auto add=arr.find(val);
    if(add!=arr.end())//found
    {
        arr.erase(add);
        auto it=arr.begin();
        auto end=arr.end();
        end--;
        while(it!=end)
        {
            cout<<*it<<" ";
            it++;
        }
        return;
    }
    else 
    {
        cout<<-1;
        return;
    }
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