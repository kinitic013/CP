#include<bits/stdc++.h>
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
    vi arr;
    int fre[32]={0};
    REP(i,0,n)
    {
        int ele;cin>>ele;
        int j=1;
        while(ele)
        {
            if(ele&1)
            {
                fre[j]++;
            }
            ele/=2;
            j++;
        }
    }
    REP(i,1,n+1)
    {
        int j=1;
        for(;j<32;j++)
        {
            ll val=fre[j]%i;
            if(val!=0)
            {
                break;
            }
        }
        if(j==32)
        {
            cout<<i<<" ";
        }

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
