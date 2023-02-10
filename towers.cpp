#include<bits/stdc++.h>//❤️❤️❤️❤️
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
    ll n,k;cin>>n>>k;
    multimap<ll,ll> arr;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        arr.insert({ele,i+1});
    }
    vector<pii> result;
    if(n==1)
    {
        cout<<0<<" "<<0;
        return;
    }
    while(1)
    {
        ll move=min(((++arr.begin())->ff-arr.begin()->ff),(arr.rbegin()->ff-(++arr.rbegin())->ff));move++;
        move=min(move,k);
        move=1;
        if(move<=0)
        break;
        if(arr.rbegin()->ff-arr.begin()->ff==0)
        break;
        pii l={arr.begin()->ff+move,arr.begin()->ss};
        pii r={arr.rbegin()->ff-move,arr.rbegin()->ss};
        k-=move;
        arr.erase(arr.begin());
        arr.erase(--arr.end());
        REP(i,0,move)
        {
            result.pb({r.ss,l.ss});
        }
        arr.insert(l);
        arr.insert(r);

        if(k==0)
        {
            break;//❤️❤️❤️❤️❤️
        }
    }
    cout<<arr.rbegin()->ff-arr.begin()->ff<<" "<<result.size()<<endl;
    REP(i,0,result.size())
    {
        cout<<result[i].ff<<" "<<result[i].ss<<endl;
    }
    return;

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
