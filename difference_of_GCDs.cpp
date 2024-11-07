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
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n,l,r;
    cin>>n>>l>>r;
    vi arr(n+1,0);
    //arr.pb(l);
    int val=l;
    int idx=l;
    int i=n;
    while(i>0)
    {
        idx=val/i;
        {
            if(idx*i<val)
            idx++;

            val=idx*i;
            if(val>r)
            {
                cout<<"NO";
                return;
            }
            arr[i]=val;
        }
        val=l;
        i--;
    }
    cout<<"YES"<<endl;
    REP(i,1,n+1)
    {
        cout<<arr[i]<<" ";
    }
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