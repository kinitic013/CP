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
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll n,m;cin>>n>>m;
    vi arr(n);
    vi prefix(n);
    ll val;
    REP(i,0,n) 
    {
        cin>>arr[i];
        if(i!=0)
        prefix[i]=arr[i]+prefix[i-1];
        else
        prefix[i]=arr[i];
    }
    ll count=0;
    val=prefix[m-1];
    priority_queue<ll> set;
    for(ll i=m-1;i>=0;i--)
    {
        while(prefix[i]<val)
        {
            count++;
            val+=(-2)*(set.top());
            set.pop();
        }
        set.push(arr[i]);
    }
    priority_queue <ll, vector<ll>, greater<ll>> st;
    val=prefix[m-1];
    REP(i,m,n)
    {
        st.push(arr[i]);
        while(prefix[i]<val)
        {
            count++;
            val+=(2*st.top());
            st.pop();
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
