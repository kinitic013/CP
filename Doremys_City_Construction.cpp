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
    int n;cin>>n;input
    mii fre;
    REP(i,0,n)
    {
        fre[arr[i]]++;
    }
    ll result=LONG_LONG_MIN;
    bool notequal=0;
    REP(i,0,n-1)
    {
        if(arr[i]!=arr[i+1])
        {
            notequal=1;
            break;
        }
    }
    if(!notequal)
    {
        cout<<n/2;
        return;
    }
    auto it=fre.begin();
    ll sum=0;
    while(it!=fre.end())
    {
        sum+=it->ss;
        ll val=sum*(n-sum);
        result=max(val,result);
        it++;
    }
    cout<<result;
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