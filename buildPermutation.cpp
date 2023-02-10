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
#define REP(i,a,b) for(int i=a;i<b;i++)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    int sq=sqrt(n-1);
    if((n-1)!=sq*sq)//a perfect square
    {
        sq++;
    }
    sq*=sq;
    int size=n;
    int count=0;
    while(sq)
    {
        vector<pii> list;
        for(int i=0;i<=sq/2;i++)
        {
            if((sq-i)<=n-1)
            {
                list.pb(mp(i,sq-i));
            }
        }
        REP(i,0,list.size())
        {
            if(arr[list[i].first]==0)
            {
                count++;
                arr[list[i].ff]=list[i].ss;
                arr[list[i].ss]=list[i].ff;
            }
        }
        if(count==size)
        {
            break;
        }
        sq=sqrt(sq);
        sq--;
        sq*=sq;
    }   
    REP(i,0,n)
    cout<<arr[i]<<" ";
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