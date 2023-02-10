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
#define vip vector<pii>
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
    vip arr;
    REP(i,0,n)
    {
        string temp;cin>>temp;
        REP(j,0,n)
        {
            if(temp[j]=='1')
            {
                arr.pb({i+1,j+1});
            }
        }
    }
    vi temp={0};
    vector<vi> result(n+1);
    REP(i,0,arr.size())
    {
        if(result[arr[i].ss].empty())
        {
            result[arr[i].ss].pb(arr[i].ss);
        }
        result[arr[i].ss].pb(arr[i].ff);
    }
    REP(i,1,n+1)
    {
        
        if(result[i].empty())
        {
            result[i].pb(i);
        }
        cout<<result[i].size()<<" ";
        REP(j,0,result[i].size())
        {

            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

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
