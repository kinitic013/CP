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
#define b begin
#define e end
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
// My approach is first calculate diff. interval and sort them in descending order now first save that interval
// that have max length 
// with each day for every interval otherthan max size interval is going to face decrement of 2 houses while interval with max
// size  is going to lose 1 house
// then we just check until all unsaved house are infected
void  solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    vector<ll> list;
    REP(i,0,k)
    {
        ll ele;
        cin>>ele;
        list.push_back(ele);
    }
    sort(list.begin(),list.end());
    ll ele2=list[0];// start
    ll fir=ele2;
    ll ele1;// end
    REP(i,1,k)
    {
        
        ele1=list[i];
        arr.push_back((ele1-1)%(n+1)-(ele2+1)%(n+1)+1);
        ele2=ele1;
    }
    ll val=(fir-1)%(n+1)+n-(ele2+1)%(n+1)+1;
    if (val > n)
        val = val % (n + 1);
    arr.push_back(val);

    sort(arr.begin(),arr.end());
    reverse(arr.b(),arr.e());
    ll count=0;
    REP(i,0,k)
    {
        arr[i]-=(i)*4;
        if(arr[i]-2<0)
        {
            if(arr[i]>0)
            count++;
            cout<<n-count;
            return;
        }
        count+=(arr[i]-1);
    }
    cout<<n-count;
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