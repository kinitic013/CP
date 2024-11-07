#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vpii vector<pii>
#define pairMinHeap priority_queue<pii , vpii, greater<pii> > 
#define aint(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = a; i < b; i++)
#define revREP(i,a,b) for (int i = a ; i>b ; i--)
#define MOD (int)(1e9 + 7)
#define mod (int)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
// array containing aint divisors
vi Divisors(int n)
{
    vi ans;
    // Note that this loop runs tiint square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                ans.pb(i);
            else
            {
                ans.pb(i);
                ans.pb(n/i);
            }     
        }
    }
    return ans;
}
int gcd( int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
void solve(vi& p)
{
    int n,m;cin>>n>>m;
    vvi arr(n,vi(m));
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            int ele;cin>>ele;
            arr[i][j] = ele;
        }
    }
    int constant = gcd(arr[0][0] ,  arr[n-1][m-1]);
    int ans = 1;
    vi divisors = Divisors(constant);
    for(auto x : divisors)
    {
        if (x == 1)
        continue;

        queue<pii> q;
        q.push({0,0});
        bool flag = 0;
        while(!q.empty())
        {
            pii idx = q.front();
            if(idx.ff == n-1 && idx.ss == m-1)
            {
                ans = max(ans , x);
            }

            q.pop();

            //right
            if(idx.ss + 1 < m)
            {
                if(arr[idx.ff][idx.ss+1]%x == 0)
                {
                    q.push({idx.ff,idx.ss+1});
                }
            }
            // down
            if(idx.ff + 1 < n)
            {
                if(arr[idx.ff+1][idx.ss]%x == 0)
                {
                    q.push({idx.ff+1,idx.ss});
                }
            }
        }
    }
    cout<<ans;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vi p;
    int ele = 1;
    REP(i,0,32)
    {
        p.pb(ele);
        ele*=2;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve(p);
        cout << endl;
    }
    return 0;
}