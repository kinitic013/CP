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
    map<ll,ll> arr;
    REP(i,0,n)
    {
        int ele;cin>>ele;
        arr[ele]++;
    }
    auto it=arr.end();
    it--;
    if(arr.size()==1)
    {
        if((arr.begin()->ss)&1)
        {
            cout<<"Marichka";
            return;
        }
        else
        {
            cout<<"Zenyk";
        }
        return;
    }
    while(it!=arr.begin())
    {
        if((it->ss)&1)
        {
            cout<<"Marichka";
            return;
        }
        it--;
    }
    if(it==arr.begin())
        {
            if((arr.begin()->ss)&1)
            {
                cout<<"Marichka";
                return;
        }
    }
    cout<<"Zenyk";
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
