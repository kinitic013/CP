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
#define input vi result;REP(i,0,n){ll ele;cin>>ele;result.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll a,b;cin>>a>>b;
    set<ll> result;
    ll n=a+b;
    if(n%2==0)
    {
        ll x;
        REP(i,0,(n/2)+1)
        {
            x=(n/2)+i-a;
            if(x<=(n/2) && x>=0)
            {
                result.insert(x+i);
            }
        }
    }   
    else
    {
        ll x;
        REP(i,0,(n/2)+1)
        {
            {
                x=(n/2)+1+i-a;
                if(x<=((n/2)+1) && x>=0)
                {
                    result.insert(x+i);
                }
            }
        }
        REP(i,0,(n/2)+2)
        {
            {
                x=(n/2)+i-a;
                if(x<=(n/2) && x>=0)
                {
                    result.insert(x+i);
                }
            }
        }
    }
    auto it=result.begin();
    cout<<result.size()<<"\n";
    while(it!=result.end())
    {
        cout<<*it<<" ";
        it++;
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
