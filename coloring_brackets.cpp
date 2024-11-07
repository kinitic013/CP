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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    string arr;cin>>arr;
    char r=arr[0];
    char l;
    ll R=0,L=0;
    if(r=='(')
    l=')';
    else
    l='(';
    set<ll> li,ri;
    REP(i,0,n)
    {
        if(arr[i]==l)
        {
            L++;
            li.insert(i);
        }
        else
        {
            R++;
            ri.insert(i);
        }
    }
    if(n&1 || L!=R)
    {
        cout<<-1;
        return;
    }
    vi ans(n,2);
    auto it=ri.begin();
    bool flag=1;
    while(it!=ri.end())
    {
        auto add=li.upper_bound(*it);
        if(add==li.end())
        {
            flag=0;
            break;
        }
        ans[*it]=1;
        ans[*add]=1;
        li.erase(add);
        it++;
    }
    if(flag)
    cout<<1<<endl;
    else
    cout<<2<<endl;
    REP(i,0,n)
    cout<<ans[i]<<" ";
    return;
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
