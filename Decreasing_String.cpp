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
#define vpii vector<pii>
#define pairMinHeap priority_queue<pii , vpii, greater<pii> > 
#define all(x) (x).begin(), (x).end()
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define revREP(i,a,b) for (ll i = a ; i>b ; i--)
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
char solve()
{
    string arr;cin>>arr;
    ll n = arr.size();
    ll x;cin>>x;
    ll count = 0;
    ll times = 0;
    ll prev = 0;
    for(int i=n;i>=0;i--)
    {
        count+=i;
        if(count >= x)
        {
            break;
        }
        times++;
        prev +=i;
    }
    ll total = 0;
    string s;
    s.push_back(arr[0]);
    bool flag = 0;
    REP(i,1,n)
    {
        if(total == times)
        {
            flag = 1;
        }
        if(s.empty())
        {
            s.push_back(arr[i]);
        }
        else
        {
            ll top = s[s.length() - 1];
            if(!flag && arr[i] < top)
            {
                s.pop_back();
                total++;
                i--;
            }
            else
            {
                s.push_back(arr[i]);
            }
        }
    }
    // cout<<s;
    return (char)s[x-prev - 1];
}
int main()
{
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        cout<<solve();
        // cout << endl;
    }
    return 0;
}