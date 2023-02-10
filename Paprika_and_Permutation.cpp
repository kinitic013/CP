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
    vector<ll> arr;
    vector<bool> check(n+1,false);
    vi range;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        if(ele<=n && !check[ele])
        {
            check[ele]=1;
            continue;
        }
        if(ele%2==0)
        range.pb(ele/2-1);
        else
        range.pb(ele/2);

        arr.pb(ele);
    }

    ll count=0;
    sort(range.begin(),range.end());
    ll j=0;
    REP(i,1,n+1)
    {
        if(check[i])
        {
            continue;
        }
        count++;
        if(range[j]<i)
        {
            cout<<-1;
            return;
        }
        j++;
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
