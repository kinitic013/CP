#include <bits/stdc++.h>

#include <bits/stdc++.h>
/* Uncomment following line to see Debug code on leetcode */
// #define cerr cout
namespace _DEBUG_UTIL_
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) {}
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> x)
    {
        /* vector<bool> doesn't work in general iteration template because of rvalue problems */
        int f = 0;
        cerr << '{';
        for (bool i : x)
        {
            cerr << (f++ ? "," : "");
            cerr << (i ? "T" : "F");
        }
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N>
    void print(T (&matrix)[N]);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T>
    void print(priority_queue<T> pq);
    template <typename T>
    void print(priority_queue<T, vector<T>, greater<T>> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T x)
    {
        /* This works for every container that supports range-based loop i.e. vector, set, map, dequeue */
        int f = 0;
        cerr << '{';
        for (auto i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        /* Specialized for 2D to format every 1D in new line */
        int f = 0;
        cerr << "{\n";
        for (auto i : mat)
            cerr << (f++ ? ",\n" : ""), print(i);
        cerr << "}\n";
    }
    template <typename T, size_t N>
    void print(T (&matrix)[N])
    {
        /* Helps in iterating through matrixays and prevent decays */
        int f = 0;
        cerr << '{';
        for (auto &i : matrix)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        /* Helps in iterating through 2D matrixays and prevent decays and also print matrixays in new line */
        int f = 0;
        cerr << "{\n";
        for (auto &i : mat)
            cerr << (f++ ? ",\n" : ""), print(i);
        cerr << "}\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        /* Works for pairs and iterating through maps */
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T>
    void print(priority_queue<T> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(priority_queue<T, vector<T>, greater<T>> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions responsible for.... printing beautifully ? */
    template <typename T>
    void printer(const char *name, T &&head)
    {
        /* Base conditions for printer */
        cerr << name << " = ";
        print(head);
        cerr << "]\n";
    }
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int bracket = 0, i = 0;
        while (names[i] != ',' or bracket != 0)
        {
            if (names[i] == '(')
                bracket++;
            else if (names[i] == ')')
                bracket--;
            i++;
        }
        cerr.write(names, i) << " = ";
        print(head);
        cerr << " ||";
        printer(names + i + 1, tail...);
    }
    /* Printermatrix */
    template <typename T>
    void printermatrix(const char *name, T matrix[], int N)
    {
        cerr << name << " : {";
        for (int i = 0; i < N; i++)
        {
            cerr << (i ? "," : ""), print(matrix[i]);
        }
        cerr << "}]\n";
    }
}
/* Before submitting on LeetCode (Not CodeForces), change #ifndef to #ifdef */
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugmatrix(matrix, n) std::cerr << __LINE__ << ": [", _DEBUG_UTIL_::printermatrix(#matrix, matrix, n)
#else
#define debug(...)
#define debugmatrix(matrix, n)
#endif


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
// #define mod (ll)998244353
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
ll gcd( ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
void solve(vi& p)
{
    ll n,m,k;cin>>n>>m>>k;
    vvi matrix(n,vi(m,0));
    REP(i,0,n)
    {
        REP(j,0,m)
        cin>>matrix[i][j];
    }
    vector<string> state;
    REP(i,0,n)
    {
        string ele;cin>>ele;
        state.pb(ele);
    }
    // 1-0
    ll oneSum = 0;
    ll zeroSum = 0;
    vvi dp(n,vi(m,0));
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            if(state[i][j] == '0')
            zeroSum+= matrix[i][j];
            else
            oneSum+= matrix[i][j];

            ll top = 0;
            ll left = 0;
            ll cross = 0;
            if(i-1>=0)
            top = dp[i-1][j];
            if(j-1>=0)
            left = dp[i][j-1];
            if(i-1>=0 && j-1>=0)
            cross = dp[i-1][j-1];
            
            ll curr = -1;
            if(state[i][j] == '1')
            curr = 1;
            dp[i][j] = top + left - cross + curr;
        }
    }
    debug(dp);
    debug(state);
    ll diff = oneSum - zeroSum;
    vi arr;
    REP(i,k-1,n)
    {
        REP(j,k-1,m)
        {
            ll top = 0,left = 0,cross = 0;
            if(i-k>=0)
            top = dp[i-k][j];
            if(j-k>=0)
            left = dp[i][j-k];
            if(i-k>=0 && j-k>=0 )
            cross = dp[i-k][j-k];

            ll curr = dp[i][j] - top - left + cross;
            if(curr)
            arr.pb(abs(curr));
        }
    }
    if(arr.size() == 0)
    {
        if(diff == 0)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        return;
    }
    ll gd = arr[0];
    REP(i,0,arr.size())
    gd = gcd(arr[i],gd);

    if(gd == 0 )
    {
        cout<<"NO";
        return;
    }
    if(abs(diff)%gd == 0)
    cout<<"YES";
    else
    cout<<"NO";
    return;
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