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
ll depth(vi& parent_curr,ll node)
{
    if(node == 1)
    {
        return 0;
    }
    return 1 + depth(parent_curr,parent_curr[node]);
}
bool isSame(std::pair<long long, long long>& p1, 
                        std::pair<long long, long long>& p2) {
    return (p1.first == p2.first && p1.second == p2.second) ||
           (p1.first == p2.second && p1.second == p2.first);
}
bool dfs(vvi& child_need,vvi& child_curr ,vb& segTree,ll node)
{
    if(child_curr[node].empty() || child_need[node].empty())
    {
        if(child_need[node].empty() && child_curr[node].empty())
        {
            segTree[node] = 1;
        }
        else
        {
            if(!child_curr[node].empty())
            {
                dfs(child_curr,child_need,segTree,child_curr[node][0]);
                dfs(child_curr,child_need,segTree,child_curr[node][1]);
            }
            segTree[node] = 0;
        }
        return segTree[node];
    }
    bool res = 1;
    ll c2 = child_need[node][1];
    ll c1 = child_need[node][0];
    
    res =( res & dfs(child_need,child_curr,segTree,child_curr[node][1])) & dfs(child_need,child_curr,segTree,child_curr[node][0]);
    
    pii c3={child_curr[node][0],child_curr[node][1]};
    pii c4={c1,c2};

    if(!isSame(c3,c4))
    {
        res = false;
    }
    segTree[node] = res; 
    return res;
}
void propogate(vvi& child_need, vvi& child_curr , vi& parent_need, vi& parent_curr , vb& segTree,ll node)
{
    if(node <=0 )
    return;

    if(child_curr[node].empty() || child_need[node].empty())
    {
        if(child_need[node].empty() && child_curr[node].empty())
        {
            segTree[node] = 1;
        }
        else
        {
            segTree[node] = 0;
        }
    }
    else
    {
        bool res = 1;
        ll c1 = child_need[node][0];
        ll c2 = child_need[node][1];
        {
            res = (res & segTree[child_curr[node][1]]) & segTree[child_curr[node][0]];

            pii c3={child_curr[node][0],child_curr[node][1]};
            pii c4={c1,c2};

            if(!isSame(c3,c4))
            {
                res = false;
            }
        }
        segTree[node] = res;
    }
    propogate(child_need,child_curr,parent_need,parent_curr,segTree,parent_curr[node]);
}
void update(vvi& child_need, vvi& child_curr , vi& parent_need, vi& parent_curr , vb& segTree,ll a,ll b)
{
    if(parent_curr[a] == b)
    {
        REP(i,0,child_curr[parent_curr[b]].size())
        {
            if(child_curr[parent_curr[b]][i] == b)
            child_curr[parent_curr[b]][i] = a;
        }

        parent_curr[a] = parent_curr[b];
        parent_curr[b] = a;  

        for(auto x : child_curr[a])
        {
            parent_curr[x] = b;
        }
        for(auto x : child_curr[b])
        {
            if(x != a)
            parent_curr[x] = a;
        }

        vi temp_child = child_curr[b]; 
        child_curr[b] = child_curr[a];
        child_curr[a] = temp_child;

        REP(i,0,2){
            if(child_curr[b][i]==b)
            child_curr[b][i] = a;
        }

        REP(i,0,2){
            if(child_curr[a][i]==a)
            child_curr[a][i] = b;
        }
        propogate(child_need,child_curr,parent_need,parent_curr,segTree,a);
        propogate(child_need,child_curr,parent_need,parent_curr,segTree,b);
    }
    else if(parent_curr[b] == a)
    {
        REP(i,0,child_curr[parent_curr[a]].size())
        {
            if(child_curr[parent_curr[a]][i] == a)
            child_curr[parent_curr[a]][i] = b;
        }

        parent_curr[b] = parent_curr[a];
        parent_curr[a] = b;  

        for(auto x : child_curr[b])
        {
            parent_curr[x] = a;
        }
        for(auto x : child_curr[a])
        {
            if(x != b)
            parent_curr[x] = b;
        }

        vi temp_child = child_curr[a]; 
        child_curr[a] = child_curr[b];
        child_curr[b] = temp_child;

        REP(i,0,2){
            if(child_curr[a][i]==a)
            child_curr[a][i] = b;
        }
    
        REP(i,0,2){

            if(child_curr[b][i]==b)
            child_curr[b][i] = a;
        }
        propogate(child_need,child_curr,parent_need,parent_curr,segTree,b);
        propogate(child_need,child_curr,parent_need,parent_curr,segTree,a);
    }
    else
    {
        parent_curr[a] = parent_curr[b]^parent_curr[a];
        parent_curr[b] = parent_curr[b]^parent_curr[a];
        parent_curr[a] = parent_curr[b]^parent_curr[a]; 

        for(auto x : child_curr[a])
        {
            parent_curr[x] = b;
        }
        for(auto x : child_curr[b])
        {
            parent_curr[x] = a;
        }

        vi temp_child = child_curr[a]; 
        child_curr[a] = child_curr[b];
        child_curr[b] = temp_child;

        if(parent_curr[a] != parent_curr[b])
        {
            for(int i=0;i<child_curr[parent_curr[a]].size();i++)
            {
                if(child_curr[parent_curr[a]][i] == b)
                child_curr[parent_curr[a]][i] = a;
            }
            for(int i=0;i<child_curr[parent_curr[b]].size();i++)
            {
                if(child_curr[parent_curr[b]][i] == a)
                child_curr[parent_curr[b]][i] = b;
            }
        }
        propogate(child_need,child_curr,parent_need,parent_curr,segTree,a);
        propogate(child_need,child_curr,parent_need,parent_curr,segTree,b);
    }
}
void helper(vvi& adj,ll k,ll parent,vi& order,ll& idx,ll level)
{
    if(idx>=order.size())
    return;
    if(level == k)
    return;
    if(adj[parent].size() == 2)
    return;

    adj[parent].pb(order[idx]);
    ll next = order[idx];
    idx++;
    helper(adj,k,next,order,idx,level+1);

    if(idx>=order.size())
    return;
    if(level == k)
    return;
    if(adj[parent].size() == 2)
    return;
    
    adj[parent].pb(order[idx]);
    next = order[idx];
    idx++;
    helper(adj,k,next,order,idx,level+1);
}
vector<vector<ll>> constructPerfectBinaryTree(vector<ll>& nodes) {
    int n = nodes.size();
    int k = log2(n);  // Calculate k where n = 2^k - 1
    vector<vector<ll>> adjList(n + 1);  // +1 because 1-indexed
    ll idx = 1;
    ll level = 0;
    helper(adjList,k,nodes[0],nodes,idx,0);
    return adjList;
}
void helper_dfs(vvi&adj,ll node,ll parent,vi&arr)
{
    arr[node] = parent;
    for(auto x : adj[node])
    {
        if(x != parent)
        {
            helper_dfs(adj,x,node,arr);
        }
    }
}
void solve(ll t)
{
    ll n,q;cin>>n>>q;
    vi parent_curr(n+1,0);
    vi parent_need(n+1,0);
    vvi child_curr(n+1);
    vvi child_need(n+1);
    ll height = log2(n+1);
    vi df;

    REP(i,2,n+1)
    {
        cin>>parent_need[i];
        child_need[parent_need[i]].pb(i);
    }
    REP(i,1,n+1)
    {
        cin>>parent_curr[i];
        df.pb(parent_curr[i]);
    }
    child_curr = constructPerfectBinaryTree(df);
    helper_dfs(child_curr,1,0,parent_curr);
    vb segTree(n+1,false);
    // True is all childs are true and childs are same
    // else False
    dfs(child_need,child_curr,segTree,1);
    REP(i,0,q)
    {
        ll a,b;cin>>a>>b;
        update(child_need,child_curr,parent_need,parent_curr,segTree,a,b);
        if(segTree[1])
        cout<<"YES\n";
        else
        cout<<"NO\n";
        cout.flush();
    }
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