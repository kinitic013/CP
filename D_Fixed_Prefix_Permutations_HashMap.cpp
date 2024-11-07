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
vi inverse(vi& arr)
{
    ll n =arr.size();
    vi res(n,0);
    REP(i,0,n)
    {
        res[arr[i]-1] = i+1;
    }
    return res;
}
ll arrayToNumber(const std::vector<ll>& array) {
    ll number = 0;
    ll size = array.size();
    for (ll i = 0; i < size; ++i) {
        number += array[i] * pow(10, size - i - 1);
    }
    return number;
}

void solve(vi& p)
{
    ll n ,m;cin>>n>>m;
    map<ll,bool> hashmap;
    vvi arr(n,vi(m));
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            cin>>arr[i][j];
        }
        vi inv =  arr[i];
        ll num = arrayToNumber(inv);
        vi array = inverse(arr[i]);
        arr[i] = array;
        hashmap[num] = 1;
        REP(j,0,m-1)
        {
            ll pos = -1, maxi = -1;
            REP(k,0,m)
            {
                if(inv[k] > maxi)
                {
                    maxi = inv[k];
                    pos = k;
                }
            }
            inv[pos] = 0;
            num = arrayToNumber(inv);
            hashmap[num] = 1; 
        }
    }
    REP(i,0,n)
    {
        ll ans = 0;
        REP(j,0,m)
        {
            ll num = arrayToNumber(arr[i]);
            bool found = hashmap[num];
            if(found)
            {
                ans = m-j;
                break;
            }
            ll pos = -1, maxi = -1;
            REP(k,0,m)
            {
                if(arr[i][k] > maxi)
                {
                    maxi = arr[i][k];
                    pos = k;
                }
            }
            arr[i][pos] = 0;
        }
        cout<<ans<<" ";
    }
    return ;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vi p;
    ll ele = 1;
    REP(i,0,32)
    {
        p.pb(ele);
        ele*=2;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        solve(p);
        cout << endl;
    }
    return 0;
}