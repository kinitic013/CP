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
#define MOD (ll)(1e9+7)
template<class T>
void input(vector<T>&arr,ll n)
{

    REP(i,0,n)
    {
        T ele;cin>>ele;
        arr.pb(ele);
    }
    return;
}

void  solve()
{
    ll n;cin>>n;
    map<ll,ll> arr;
    vi temp1;vi temp2;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        temp1.pb(ele);
    }
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        temp2.pb(ele);
    }
    
    REP(i,0,n)
    {
        arr.insert({temp1[i],temp2[i]});
    }
    auto it=arr.begin();
    ll count=1;
    ll initial=it->ff;
    if(n==1)
    {
        if(arr.begin()->ff==arr.begin()->ss)
        {
            cout<<1;return;
        }
        else
        {
            cout<<2;return;
        }
    }
    while(n)
    {

        auto add=arr.find(it->ss);
        if(add==arr.end() || add->ss==initial)
        {
            count=(count*2)%(MOD);
            n--;
            arr.erase(it);
            if(arr.empty())
            {
                break;
            }
            if(add!=arr.end())
            {
                n--;
                arr.erase(add);
                if(arr.empty())
                {
                    break;
                }
            }

            it=arr.begin();
            initial=it->ff;
        }
        else
        {
            arr.erase(it);
            if(arr.empty())
            {
                break;
            }
            n--;
            it=add;
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
