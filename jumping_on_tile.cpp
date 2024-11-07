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
void  solve()
{
    string str;cin>>str;
    ll n=str.size();
    map<ll,vector<ll>> arr;
    ll cost=0,count=0;
    ll last=str[0];
    bool flag=0;
    REP(i,0,n)
    {
        if(str[0]>str[n-1])
        {
            flag=1;
            if (str[i] <= str[0] && str[i] >= str[n - 1])
            {
                arr[str[i]-97+1].push_back(i);
                count++;
            }
        }
        else if(str[0]<=str[n-1])
        {
            if (str[i] >= str[0] && str[i] <= str[n - 1])
            {
                arr[str[i]-97+1].push_back(i);
                count++;
            }
        }
    }
    cost=abs(str[0]-str[n-1]);
    cout<<cost<<" "<<count<<'\n';
    auto it1=arr.begin();
    vi result;
    if(flag)
        {
            auto it2=arr.end();
            it2--;
            reverse(it2->ss.begin(),it2->ss.end());
            it2=arr.begin();
            reverse(it2->ss.begin(),it2->ss.end());
        }
    while(it1!=arr.end())
    {
        for(ll i=0;i<it1->ss.size();i++)
        {
            result.pb(it1->ss[i]+1);
        }
        it1++;
    }
    if(flag)
    {
        reverse(result.begin(),result.end());
    }
    for(ll i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
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