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
    input
    ll k=(n/2)+(n%2);ll j=k+1;
    ll result=0;
    if(n==1)
    {
        cout<<1;
        return;
    }
    while(j--)
    {
        multiset<ll> temp;
        REP(i,0,n)
        {
            temp.insert(arr[i]);
        }
        ll i=1;
        bool flag=0;
        for(;i<k+1;i++)
        {
            ll val=k-i+1;
            
            auto add=temp.upper_bound(val);
            if(add==temp.begin())
            {
                flag=1;
                break;
            }
            else
            add--;

            temp.erase(add);
            if(temp.empty())
            {
                break;
            }
            ll ele=*temp.begin();
            temp.erase(temp.begin());
            if(temp.empty())
            {
                break;
            }
        }
        if(!flag)
        {
            cout<<k;
            return;
        }
        k--;
    }
    cout<<result;
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
