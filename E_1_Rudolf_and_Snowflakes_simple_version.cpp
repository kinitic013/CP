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
ll cal(ll k, ll it) {
    ll sum = 1, curr = 1;
    for (ll i = 0; i < it; i++) {
        curr *= k;
        sum += curr;
    }
    return sum;
}
void solve(ll t)
{
    long long n;cin>>n;
    if(n<=6)
    {
        cout<<"NO";
        return;
    }
    REP(p,2,63)
    {
        ll l = 2;
        double a = double(1) / double(p);
        double bound = pow(n, a) + 1;
        ll r = bound;
        ll counter = 31;
        while(counter--)
        {
            ll mid = (l + r)/2;
            ll val = cal(mid,p);
            if(val == n)
            {
                cout<<"YES";
                return;
            }
            else if( val > n)
            r = mid;
            else
            l = mid+1;
        }
        ll value = cal(l,p);
        if(value == n)
        {
            cout<<"YES";
            return;
        }
        value = cal(r,p);
        if(value == n)
        {
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
    return;

}
int main()
{
    fast();
    long long t;
    cin >> t;
    REP(T,1,t+1)
    {
        solve(T);
        cout << endl;
    }
    return 0;
}