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
    void print(T (&arr)[N]);
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
    void print(T (&arr)[N])
    {
        /* Helps in iterating through arrays and prevent decays */
        int f = 0;
        cerr << '{';
        for (auto &i : arr)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        /* Helps in iterating through 2D arrays and prevent decays and also print arrays in new line */
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
    /* PrinterArr */
    template <typename T>
    void printerArr(const char *name, T arr[], int N)
    {
        cerr << name << " : {";
        for (int i = 0; i < N; i++)
        {
            cerr << (i ? "," : ""), print(arr[i]);
        }
        cerr << "}]\n";
    }
}
/* Before submitting on LeetCode (Not CodeForces), change #ifndef to #ifdef */
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(arr, n) std::cerr << __LINE__ << ": [", _DEBUG_UTIL_::printerArr(#arr, arr, n)
#else
#define debug(...)
#define debugArr(arr, n)
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
ll dfs_a(vvi& adj,vi& depth,ll node,ll parent)
{
    ll res = node;
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            depth[x] = depth[node] + 1;
            ll val = dfs_a(adj,depth,x,node);
            if(depth[val] > depth[res])
            {
                res = val;
            }
        }
    }
    return res;
}
bool dfs(vvi& adj,vi& path,ll node,ll parent,ll target)
{
    path.pb(node);

    if(node == target)
    return 1;

    for(auto x : adj[node])
    {
        if(x != parent)
        {
            bool curr = dfs(adj,path,x,node,target);
            if(curr)
            return curr;
        }
    }   
    path.pop_back();
    return false;
}
pii coun(vvi& adj,ll node,ll prev,ll next,ll parent)
{
    pii res = {0,node};
    for(auto x : adj[node])
    {
        if( x != prev && x != next && x != parent)
        {
            pii curr = coun(adj,x,prev,next,node);
            if(res.ff <= 1 + curr.ff)
            {
                res = curr;
                res.ff++;
            }
        }
    }
    return res;

}
void greedy(ll t)
{
    ll n;cin>>n;
    vvi adj(n+1);
    vi depth(n+1,0);
    REP(i,0,n)
    {
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll a = dfs_a(adj,depth,1,0);
    depth = vi(n+1,0);
    ll b = dfs_a(adj,depth,a,0);
    vi path;
    dfs(adj,path,a,0,b);
    debug(path);
    ll val = abs(depth[a]-depth[b]);
    ll ans = val;
    ll c= 0;
    REP(i,1,path.size()-1)
    {
        ll prev = path[i-1];
        ll next = path[i+1];
        pii current = coun(adj,path[i],prev,next,0);
        ll curr = val + current.ff;
        if(curr >= ans)
        {
            c = current.ss;
            ans = curr;
        }
    }
    cout<<ans<<endl;
    cout<<a<<" "<<b<<" "<<c;
    return;
}
void helper2(vvi& adj,vpii& first,vpii& second,ll node,ll parent)
{
    pii second_maxi = {INT_MIN,0};
    pii maxi = {INT_MIN,0};
    maxi = second[node];
    if(node != 1)
    maxi.ff++;
    ll child = 0;
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            child++;
            if(second_maxi.ff <= first[x].ff + 1)
            {
                second_maxi = first[x];
                second_maxi.ff++;
            }
            if(second_maxi.ff > maxi.ff)
            {
                swap(maxi,second_maxi);
            }
        }
    }
    if(child == 1)
    {
        for(auto x : adj[node])
        {
            if(x != parent)
            {
                second[x] = second[node];
                second[x].ff++;
                helper2(adj,first,second,x,node);
            }
        }
        return;
    }
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            if(first[x].ss != maxi.ss)
            second[x] = maxi;
            else
            second[x] = second_maxi;

            second[x].ff++;
            
        }
    }
    for(auto x : adj[node])
    {
        if(x != parent)
        helper2(adj,first,second,x,node);
    }
}
void helper1(vvi& adj,vpii& first,ll node,ll parent)
{
    first[node] = {0,node};
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            helper1(adj,first,x,node);
            if(first[x].ff + 1 >= first[node].ff)
            {
                first[node].ff = first[x].ff + 1;
                first[node].ss = first[x].ss;
            } 
        }
    }
}
void solve(ll t)
{
    ll n;cin>>n;
    vvi adj(n+1);
    REP(i,0,n)
    {
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vpii first(n+1,{0,0});
    vpii second(n+1,{0,0});
    second[0] = {0,1};
    second[1] = {-1,1};
    vvi dp(n+1,{0,0,0,0});
    helper1(adj,first,1,0);
    helper2(adj,first,second,1,0);
    debug(first);
    debug(second);
    return;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll t;
    // cin >> t;
    // REP(T,1,t+1)
    {
        solve(1);
        cout << endl;
    }
    return 0;
}