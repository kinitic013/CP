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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n;
    string arr;
    cin>>arr;
    vector<char> special;
    cin>>k;
    bool flag=1;
    REP(i,0,k)
    {
        char ele;
        cin>>ele;
        special.pb(ele);
    }
    sort(special.begin(),special.end());
    ll count=0;
    ll maxi=0;
    vi len;
    REP(i,0,n)
    {
        auto it=binary_search(special.begin(),special.end(),arr[i]);
        if(it)//found
        {
            len.pb(count);
            count=0;
        }
        else
        {
            count++;
        }
    }
    for(int i=1;i<len.size();i++)
    {
        len[i]++;
    }
    if(!len.empty())
    maxi=*max_element(len.begin(),len.end());
    else
    maxi=0;
    cout<<maxi;

    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}