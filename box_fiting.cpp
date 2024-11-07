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
    int n,w;cin>>n>>w;
    multiset<ll> arr;
    REP(i,0,n)
    {
        int ele;cin>>ele;
        arr.insert(ele);
    }
    ll size=w;
    ll count=1;
    while(!arr.empty())
    {
        auto add=arr.upper_bound(size);
        if(add==arr.begin())
        {
            count++;
            size=w;
            continue;
        }
        add--;
        size-=*add;
        arr.erase(add);
        if(size==0)
        {
            size=w;
            if(!arr.empty())
            {
                count++;
            }
        }
        
    }
    cout<<count;
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
