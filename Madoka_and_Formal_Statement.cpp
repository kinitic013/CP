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
    int n;cin>>n;
    vi a,b;
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        a.pb(ele);
    }
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        b.pb(ele);

    }
    bool flag=0;
    REP(i,0,n)
    {
        if(a[i]!=b[i])
        {
            flag=1;
        }
    }
    if(!flag)
    {
        cout<<"YES";
        return;
    }
    REP(i,0,n)
    {
        if(a[i]!=b[i])
        {
            if((b[i]-b[(i+1)%n])>1 && (b[i]!=a[i]))
            {
                cout<<"NO";
                return;
            }
            if(b[i]<a[i])
            {
                cout<<"NO";
                return;
            }
            if((b[(i+1)%n])==a[(i+1)%n])
            {
                ll ele=a[(i+1)%n];
                if(a[i]>ele)
                {
                    cout<<"NO";
                    return;
                }
                
            }
        }
    }
    cout<<"YES";
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
