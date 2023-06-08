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
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
vi power(13,0);
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
vi base10to9(ll n)
{
    vi ans;
    while(n)
    {
        ans.pb(n%9);
        n/=9;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// void  solve()
// {
//     ll n;cin>>n;
//     vi arr=base10to9(n);
//     REP(i,0,arr.size())
//     {
//         if(arr[i]>=4)
//         {
//             arr[i]++;
//         }
//     }
//     REP(i,0,arr.size())
//     cout<<arr[i];
// }
#define power 1
ll idx(ll n)
{
    ll count=0;
    string arr=to_string(n);
    ll len=arr.size();
    REP(i,0,len)
    {
        if(arr[i]>='4')
        {
            count+=(arr[i]-'2')*pow(9,len-1-i);
        }
        else
        {
            if(arr[i]=='0')
            {
                continue;
            }
            count+=(arr[i]-'0')*pow(9,len-i-1);
        }
    }
    count++;

    REP(i,0,len-1)
    {
        count+=8*pow(9,i);
    }
    return count;

}
void solve()
{
    ll n;cin>>n;
    ll val=idx(n);
    ll ans=2*n-val;
    cout<<ans;

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

