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
    int h, n;cin>>n>>h;input
    int b=1;int g=2;
    ll count=0;
    REP(i,0,n)
    {
        if(h>arr[i])
        {
            count++;
            h+=(arr[i]/2);
        }
        else
        {
            if(h*2>arr[i] && g)
            {
                g--;
                h*=2;
                i--;
                continue;
            }
            else if(h*3>arr[i] && b)
            {
                b--;
                h*=3;
                i--;continue;
            }
            else if(h*4>arr[i] && g/2)
            {
                b-=2;
                h*=4;
                i--;continue;
            }

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
