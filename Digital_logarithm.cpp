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
    int n;cin>>n;
    vi a(n),b(n);
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) cin>>b[i];
    ll count=0;
    priority_queue<ll>arr(a.begin(),a.end());
    priority_queue<ll>brr(b.begin(),b.end());
    while(!arr.empty())
    {
        if(arr.top()==brr.top())
        {
            arr.pop();
            brr.pop();
            continue;
        }
        count++;
        if(arr.top()<brr.top())
        {
            ll val=1+log10(brr.top());
            brr.pop();
            brr.push(val);
        }
        else
        {
            ll val=1+log10(arr.top());
            arr.pop();
            arr.push(val);
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
