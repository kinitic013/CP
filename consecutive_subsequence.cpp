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
    if(a.ff!=b.ff)
    return a.ff<b.ff;


    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    vi arr(n);
    map<ll,ll > m;
    REP(i,0,n) 
    {
        cin>>arr[i];
        m.insert({arr[i],0});
    }
    ll ans=1;
    REP(i,0,n)
    {
        auto add=m.find(arr[i]-1);
        if(add==m.end())//not found
        {
            ans=max(ans,(ll)1);
            m[arr[i]]=1;
        }
        else
        {
            ll val1=1+add->ss;
            ll val2=1;
            if(val1>val2)
            {
                ans=max(ans,val1);
                m[arr[i]]=val1;
            }
            else
            {
                ans=max(ans,(ll)1);
                m[arr[i]]=1;
            }
        }
    }
    cout<<ans<<endl;
    auto it=m.begin();
    ll last=-1;
    ll first=-1;
    while(it!=m.end())
    {
        if(it->ss==ans)
        {
            last=it->ff;
            break;
        }
        it++;
    }
    vi idx;
    first=last-ans+1;
    REP(i,0,n)
    {
        if(first>last)
        break;

        if(arr[i]==first)
        {
            cout<<i+1<<" ";
            first++;
        }
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
