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
/*
array-> a  b     c              d       e
1 step  x  b-a   c-a            d-a     e-a
2 step  x   x    c-a -(b-a)=c-b d-b     e-b
and so on...                            k=e-d

*/
void  solve()
{
    ll n,k;cin>>n>>k;
    input;
    multiset<int> list;
    //need to check wheather difference of 2 elements would be k or not
    REP(i,0,n)
    {
        
        auto it1=list.find((arr[i]-k));
        auto it2=list.find(arr[i]+k);
        if(it1!=list.end() || it2!=list.end())
        {
            cout<<"YES";
            return;
        }
        list.insert(arr[i]);
    }
    cout<<"NO";
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