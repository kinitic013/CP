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
vi topoSort(vvi& adj,vi& indegree)
{
    ll n = adj.size()-1;
    queue<ll> q;
    REP(i,1,n+1)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vi res;
    while(!q.empty())
    {
        ll top = q.front();
        res.pb(top);
        q.pop();
        for(auto x : adj[top])
        {
            indegree[x]--;
            if(indegree[x]==0)
            q.push(x);
        }
    }
    return res;
}
ll dfs(vvi& arr,vb& visited,vb& pathvisited,vi& c,vi& costing,ll parent , ll node,ll& start,ll& end)
{
    if(pathvisited[node])
    {
        start = node;
        end = parent;
        return node;
    }
    if(visited[node])
    return 0;

    visited[node] = 1;
    pathvisited[node] = 1;
    for(auto x : arr[node])
    {
        ll check = dfs(arr,visited,pathvisited,c,costing,node,x,start,end);
        if(check)
        {
            // if(x == start)// cyclic end
            // {
            //     ll cost = c[x] - c[end];
            //     costing[x] = cost;
            // }
            // else // in betwee the cycle
            {
                ll cost = c[x] - c[node];
                costing[x] = cost;
            }
            return check;
        }

    }
    pathvisited[node] = 0;
    return 0;
}
ll dfs2(vvi& arr,vb& visited,vb& pathvisited,vi& c,ll target,ll parent , ll node,ll start,ll end)
{
    if(pathvisited[node])
    {
        start = node;
        end = parent;
        return node;
    }
    if(visited[node])
    return 0;

    visited[node] = 1;
    pathvisited[node] = 1;
    for(int i =0;i<arr[node].size();i++)
    {
        ll x = arr[node][i];
        ll check = dfs2(arr,visited,pathvisited,c,target,node,x,start,end);
        if(check)
        {
            if(x == target)
            {
                arr[node].erase(arr[node].begin() + i);
                return 0;
            }
            return check;
        }
    }
    pathvisited[node] = 0;
    return 0;
}
void solve(ll t)
{
    ll n;cin>>n;
    vvi adj(n+1);
    vi arr(n),c(n);
    REP(i,1,n+1)
    {
        cin>>arr[i];
        ll u = i;
        ll v = arr[i];
        adj[u].pb(v);       
    }
    REP(i,1,n+1) cin>>c[i];
    vb visited(n+1,false);
    vb pathvisited(n+1,false);
    vi costing(n+1,LONG_LONG_MIN);
    ll start = -1,end = -1;
    dfs(adj,visited,pathvisited,c,costing,0,1,start,end);
    visited = vb(n+1,false);
    pathvisited = vb(n+1,false);
    ll maxi = *max_element(all(costing));
    if(maxi != LONG_LONG_MIN)// No cycle detected
    {
        ll x_node = 0;
        REP(i,1,n+1)
        {
            if(costing[i] == maxi)
            {
                start = -1;
                end = -1;
                dfs2(adj,visited,pathvisited,c,i,0,1,start,end);
                break;
            }
        }
    }
    vi indegree(n+1,0);
    REP(i,1,n+1)
    {
        REP(j,0,adj[i].size())
        {
            indegree[adj[i][j]]++;
        }
    }
    vi perm = topoSort(adj,indegree);
    for(auto x : perm)
    cout<<x<<" ";
    return;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    REP(T,1,t+1)
    {
        solve(T);
        cout << endl;
    }
    return 0;
}