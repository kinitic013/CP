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
//         int ele;
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
    cin>>n;
    set<ll> arr;
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        arr.insert(ele);
    }
    bool one=0,zero=0;
    auto it=arr.begin();
    while(it!=arr.end())
    {
        if(*it==0 ||*it==2)
        {
            zero=1;
        }
        if(*it==1)
        {
            one=1;
        }
        if(one)
        {
            auto add=it;
            add++;
            if(add!=arr.end())
            {
                if(*add-*it==1)
                {
                    cout<<"NO";
                    return;
                }
            }
        }
        if(zero && one)
        {
            cout<<"NO";
            return;
        }
        it++;
    }
    cout<<"YES";
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