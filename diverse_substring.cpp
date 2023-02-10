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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    string arr;cin>>arr;
    //need to check all substirngs with size <=100 as after 100 substring will be defitinely not a diverse substirng 
    //start
    ll count=0;
    REP(i,0,n)
    {
        ll maxi=0;
        map<char,ll> fre;
        ll limit=i+100;
        REP(j,i,min(limit,n))
        {
            fre[arr[j]]++;
            maxi=max(maxi,fre[arr[j]]);
            if(fre.size()>=maxi)
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
