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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    ll n;cin>>n;
    input
    ll result=LONG_LONG_MAX;
    ll count=0;
    REP(i,0,n)
    {   //selecting 0
        count=0;
        //+ve
        ll l=0;
        REP(j,i+1,n)
        {
            if(arr[j]>l)
            {
                count++;
                l=arr[j];
            }
            else
            {
                ll val=l/arr[j];
                val++;
                if(val*arr[j]==l)//perfect
                {
                    val++;
                }
                count+=val;
                l=val*arr[j];
            }
        }
        //-ve
        l=0;
        for(ll j=i-1;j>=0;j--)
        {
            if(-arr[j]<l)
            {
                l=-arr[j];
                count++;
            }
            else
            {
                ll val=l/arr[j];
                val--;
                if(val*arr[j]==l)//perfect
                {
                    val--;
                }
                count-=val;
                l=val*arr[j];
            }
        }
        result=min(count,result);
    }
    cout<<result;
    return ;
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
