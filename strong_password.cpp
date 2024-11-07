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
    string arr;cin>>arr;
    ll n;
    cin>>n;
    string l,r;cin>>l>>r;
    ll j=0;
    ll i=0;
    bool flag=0;
    for(;i<n;i++)
    {
        vi visited(10,0);
        ll count=0;
        if(j>=arr.size())
        {
            cout<<"YES";
            return;
        }
        while(1)
        {
            if(count>=r[i]-l[i]+1)
            {
                break;
            }
            if(j>=arr.size())
            {
                flag=1;
                break;
            }
            if(arr[j]<=r[i] && arr[j]>=l[i])
            {
                if(visited[arr[j]-'0']==0)
                {
                    visited[arr[j]-'0']=1;
                    count++;
                }
            }
            j++;
        }
    }
    if(flag)
    {
        cout<<"YES";
    }
    else
    cout<<"NO";
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
