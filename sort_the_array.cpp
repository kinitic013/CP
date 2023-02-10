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
    int n;cin>>n;
    vi arr(n); REP(i,0,n) cin>>arr[i];
    ll f=-1,s=-1;
    REP(i,1,n)
    {
        if(arr[i]<arr[i-1])
        {
            if(f!=-1)
            {
                s=i;
            }
            else
            {
                f=i-1;
                s=i;
            }
        }
        else
        {
            if(f!=-1)
            {
                break;
            }   
        }
    }
    if(f==s && f==-1)
    {
        f=0;s=0;
    }
    pii result={f,s};
    while(f<=s)
    {
        swap(arr[f],arr[s]);
        f++;
        s--;
    }
    REP(i,0,n-1)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"no";
            return;
        }
    }
    cout<<"yes"<<endl;
    cout<<result.ff+1<<" "<<result.ss+1;

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
