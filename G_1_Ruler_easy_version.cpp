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
void solve(ll t)
{
    ll l = 2;
    ll r = 999;
    ll counter = 10;
    while(counter--)
    {
        ll mid = (r+l)/2;
        cout<<"? "<<mid<<" "<<r<<endl;
        cout.flush();
        ll area;cin>>area;
        cout.flush();
        // both
        if(area == (mid+1)*(r+1))
        {
            r = mid;
        }
        else if(area == mid*(r+1))// x in between
        {
            l = mid;
        }
        else// x > r
        {
                    
        }
    }
    cout<<"! "<<r;
    cout.flush();
}
int main()
{
    ll t;
    cin >> t;
    REP(T,1,t+1)
    {
        solve(T);
        cout.flush();
    }
    cout.flush();
    return 0;
}