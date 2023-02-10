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
    ll n,m;cin>>n>>m;
    input
    vector<pii> map;
    vi fre(n,m);
    vector<vector<int>> ans(n,vector<int>(0));
    REP(i,0,m)
    {
        int ele1,ele2;
        cin>>ele1>>ele2;
        map.pb({ele1,ele2});
        ans[ele1-1].pb(arr[ele1-1]+arr[ele2-1]);
        ans[ele2-1].pb(arr[ele1-1]+arr[ele2-1]);
        fre[ele1-1]--;
        fre[ele2-1]--;
    }
    if(m%2==0)
    {
        cout<<0;
        return;
    }
    vector<pii> even,odd;
    ll mini=INT_MAX;
    REP(i,0,n)
    {
        if(fre[i]&1 && fre[i]!=m)//odd
        {
            odd.pb({arr[i],fre[i]});
            REP(j,0,ans[i].size())
            {
                if(ans[i][j]<mini)
                {
                    mini=ans[i][j];
                }
            }
        }
        else if(fre[i]%2==0 && fre[i]!=m)//even
        {
            even.pb({arr[i],fre[i]});
        }
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    if(odd.size()>1)
    {
        if(even.size()>0)
        {

            if(mini<even[0].ff)
            {
                cout<<mini;
                return;
            }
            else
            {
                cout<<even[0].ff;
                return;
            }
        }
        else
        {
            cout<<(mini);
            return;
        }
    }
    cout<<even[0].ff;
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
