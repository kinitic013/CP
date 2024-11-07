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
    ll zero,one;cin>>zero>>one;
    string result;
    if(zero>one)
    {
        if(one>=zero-1)
        {
            REP(i,0,one)
            {
                result.append("01");
            }
            result.pb('0');
        }
        else
        {
            cout<<-1;
            return;
        }
    }
    else
    {
        if(one<=(zero*2)+2)
        {
            ll o=0;
            ll val=min(one-zero,zero);
            REP(i,0,val)
            {
                result.append("110");
                o+=2;
            }
            REP(i,0,zero-val)
            {
                result.append("10");
                o+=1;
            }
            if(one-o!=0)
            {
                REP(i,0,one-o)
                {
                    result.push_back('1');
                }
            }
        }
        else
        {
            cout<<-1;
            return;
        }
    }
    cout<<result;
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
