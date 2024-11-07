
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
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
#define ll long long
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define input        \
    vi arr;          \
    REP(i, 0, n)     \
    {                \
        ll ele;      \
        cin >> ele;  \
        arr.pb(ele); \
    }
#define all(x) (x).begin(), (x).end()
const ll mod = 998244353;
#define fore(i, l, r) for (ll i = ll(l); i < ll(r); i++)
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
ll min(ll a, ll b)
{
    return a < b ? a : b;
}
struct testcase
{
    ll n;
    vi arr;
    vi brr;
};
ll randomNumber(ll a, ll b)
{
    return a + (rand() % b);
}
// Function to generate a random number between l and r
ll ran(ll l, ll r)
{
    return l + (rand() % (r - l + 1));
}
std::vector<ll> generateRandomPermutation(ll n) {
    // Create a vector with numbers from 1 to n
    std::vector<ll> permutation(n);
    for (ll i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    // Use a random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the vector
    std::shuffle(permutation.begin(), permutation.end(), g);

    return permutation;
}
bool array_compare(vi &a, vi &b)
{
    bool res = true;
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            res = false;
    }
    return res;
}
void print_array(vi &a)
{
    cout << endl;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    return;
}
testcase generateTestCase()
{
    testcase randomTest;
    ll n = randomNumber(1, 5);

    randomTest.n = n;
    randomTest.arr = generateRandomPermutation(n);
    randomTest.brr = generateRandomPermutation(n);

    cout<<n<<endl;
    print_array(randomTest.arr);
    print_array(randomTest.brr);
    return randomTest;
}
ll optimizedSolution(testcase T)
{
    ll n = T.n;
    vi p(n),posp(n+1);
    vi q(n),posq(n+1);
    REP(i,0,n){
        p[i] = T.arr[i];
        p[i]--;
        posp[p[i]] = i;
    }
    REP(i,0,n){
        q[i] = T.brr[i];
        q[i]--;
        posq[q[i]] = i;
    }
    ll ans = 1;
    ll l = min(posp[0],posq[0]);
    ll r = max(posp[0],posq[0]);
    // mex = 0;
    {
        ans += (l*(l+1))/2;
        ans += ((n-r)*(n-r-1))/2;
        ans += max(0ll,((r-l)*(r-l-1))/2);

    }
    REP(i,1,n)
    {
        ll left = 1;
        ll right = 1;
        ll L = min(posp[i],posq[i]);
        ll R = max(posp[i],posq[i]);

        if( L < l && r < R) 
        {
            left = l - L ;
            right = R - r;
            ans += left*right;
        }
        else if( (R<l)) // on the left
        {
            left = l - R;
            right = n - r ;
            ans += left*right;
        }
        else if( L>r)
        {
            right = L - r;
            left = l + 1;
            ans += left*right;
        }
        l = min(l,L);
        r = max(r,R);
    }
    return ans;
}
ll bruteForce(testcase T)
{
    int n;cin>>n;
    // dp[i] = minimum operation to set all value to from 0 to i RED
    
}

bool debugger()
{
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    cout<<endl;
    cout << "Correct ANS : " << endl;
    cout<<(ans1);
    cout << "Wrong ANS: " << endl;
    cout<<(ans2);
    cout << endl
         << endl
         << endl
         << endl;
    cout.flush();

    if ((ans1 == ans2))
        return true;

    return false;
}

void solve()
{
    while (1)
    {
        if (!debugger())
            break;
    }
}
int main()
{
    solve();
    return 0;
}
