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
#define vpi vector<pii>
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
long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
void solve()
{
    string str;cin>>str;
    ll n = str.size();
    ll count = 0;
    vpi arr;
    arr.pb({-1,-1});
    REP(i,0,n)
    {
        if(str[i] != '?')
        {
            arr.pb({str[i]-'0',count});
        }

        count++;
    }
    arr.pb({-1,count});
    if(arr.size() <=3)
    {
        cout<<(n*(n+1))/2;
        return;
    }
    ll last = 0;
    ll result = 0;
    ll lastCommon = 0;
    REP(i,1,arr.size()-1)
    {
        if(arr[i].ff == arr[i+1].ff)
        {
            ll val = arr[i+1].ss - arr[i].ss -1;
            if(!(val&1))// break point hit
            {
                ll val = arr[i+1].ss - (arr[last].ss) - 1;
                result += (val*(val+1))/2 ;
                result -= ((lastCommon)*(lastCommon+1))/2;
                last = i;
                lastCommon = arr[i+1].ss - arr[i].ss -1;
            }
        }
        else
        {
            if((arr[i+1].ss - arr[i].ss -1)&1)// break point hit
            {
                ll val = arr[i+1].ss - (arr[last].ss) - 1;
                result += (val*(val+1))/2  ;
                result -= ((lastCommon)*(lastCommon+1))/2;
                last = i;
                lastCommon = arr[i+1].ss - arr[i].ss -1;
            }
        }

        if(i == arr.size()-2)
        {
            i++;
            ll val = arr[i].ss - (arr[last].ss) - 1;
            result += (val*(val+1))/2 ;
            result -= ((lastCommon)*(lastCommon+1))/2;
            break;
        }
    }
    cout<<result;
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
        cout << endl;
    }
    return 0;
}
