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
    int n,m;cin>>n>>m;
    vector<vi> arr;
    REP(j,0,n)
    {
        vi temp(m);
        REP(i,0,m) cin>>temp[i];
        arr.pb(temp);
    }
    ll val=n;
    if(val&1)
    {
        cout<<val;
        return;
    }
    bool flag=0;
    while(val%2==0)
    {
        
        ll plus=val/2;
        ll minus=plus-1;
        while(plus<n && minus>=0)
        {
            REP(i,0,m)
            {
                if(arr[plus][i]!=arr[minus][i])
                {
                    cout<<val;
                    return;
                }
            }
            plus++;
            minus--;
        }
        val/=2;
        if(val&1)
        {
            cout<<val;
            return;
        }
    }
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
