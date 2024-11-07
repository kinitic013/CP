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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    int n,m;cin>>n>>m;
    vector<string> arr;
    REP(i,0,n)
    {
        string temp;
        cin>>temp;
        arr.pb(temp);
    }
    if(arr[0][0]=='1')
    {
        cout<<-1;
        return;
    }
    vector<pair<pii,pii>> result;
    for(int i=n-1;i>0;i--)//row
    {
        for(int j=m-1;j>=0;j--)//column
        {
            if(arr[i][j]=='1')
            {
                result.pb({{i,j+1},{i+1,j+1}}); 
            }
        }
    }
    for(int j=m-1;j>=0;j--)//column
        {
            if(arr[0][j]=='1')
            {
                result.pb({{1,j},{1,j+1}});
            }
        }
    cout<<result.size()<<endl;
    REP(i,0,result.size())
    {
        cout<<result[i].ff.ff<<" "<<result[i].ff.ss<<" ";
        cout<<result[i].ss.ff<<" "<<result[i].ss.ss<<endl;
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
