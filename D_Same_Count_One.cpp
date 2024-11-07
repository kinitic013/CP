#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vb vector<bool>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve()
{
    ll n,m;cin>>n>>m;
    vector<pair<ll,vi>> arr(n,{0,{}});
    ll oneCount = 0;
    REP(i,0,n)
    {
        vi temp;
        REP(j,0,m)
        {
            ll ele;cin>>ele;
            temp.pb(ele);
            if(ele == 1)
            {
                oneCount++;
                arr[i].ff = arr[i].ff + 1;
            }
        }
        arr[i].ss = temp;
    }
    if(oneCount%n!=0)
    {
        cout<<-1;
        return;
    }
    if(n==1)
    {
        cout<<0;
        return;
    }
    vector<pair<pair<ll,ll>,ll>> result;
    ll i = 0;//at greater than 
    ll j = 0;
    ll targetCount = oneCount/n;
    while(i<n && j<n)
    {
        while(i<n && arr[i].ff<=targetCount) i++;
        while(j<n && arr[j].ff>=targetCount) j++;

        if(i>=n || j>=n)
        {
            break;
        }
        REP(k,0,m)
        {
            if(arr[i].ff == targetCount || arr[j].ff == targetCount)
            break;

            if(arr[i].ss[k]!=arr[j].ss[k] && arr[i].ss[k] == 1)
            {
                arr[i].ff--;
                arr[j].ff++;
                result.pb({{i+1,j+1},k+1});
                swap(arr[i].ss[k],arr[j].ss[k]);
                continue;
            }
        }
    }

    cout<<result.size()<<endl;
    REP(i,0,result.size())
    {
        cout<<result[i].ff.ff<<" "<<result[i].ff.ss<<" "<<result[i].ss<<endl;
    }
    return;

}
int main()
{
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
