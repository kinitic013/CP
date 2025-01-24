#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace _DEBUG_UTIL_ {
    using namespace std;
    void print(const char *x) {} void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed int x) { cerr << x; } void print(unsigned int x) { cerr << x; }
    void print(float x) { cerr << x; } void print(double x) { cerr << x; }
    void print(string x) { cerr << '"' << x << '"'; }
    template <size_t N> void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> x) { int f = 0; cerr << '{'; for (bool i : x) cerr << (f++ ? "," : "") << (i ? "T" : "F"); cerr << "}"; }
    template <typename T> void print(T x) { int f = 0; cerr << '{'; for (auto i : x) cerr << (f++ ? "," : ""), print(i); cerr << "}"; }
    template <typename T> void print(vector<vector<T>> mat) { int f = 0; cerr << "{\n"; for (auto i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; }
    template <typename T, size_t N> void print(T (&arr)[N]) { int f = 0; cerr << '{'; for (auto &i : arr) cerr << (f++ ? "," : ""), print(i); cerr << "}"; }
    template <typename F, typename S> void print(pair<F, S> x) { cerr << '('; print(x.first); cerr << ','; print(x.second); cerr << ')'; }
    template <typename T> void print(priority_queue<T> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; }
    template <typename T> void print(stack<T> st) { int f = 0; cerr << '{'; while (!st.empty()) cerr << (f++ ? "," : ""), print(st.top()), st.pop(); cerr << "}"; }
    template <typename T> void printer(const char *name, T &&head) { cerr << name << " = "; print(head); cerr << "]\n"; }
    template <typename T, typename... V> void printer(const char *names, T &&head, V &&...tail) { int b = 0, i = 0; while (names[i] != ',' || b != 0) { if (names[i] == '(') b++; else if (names[i] == ')') b--; i++; } cerr.write(names, i) << " = "; print(head); cerr << " ||"; printer(names + i + 1, tail...); }
    template <typename T> void printerArr(const char *name, T arr[], int N) { cerr << name << " : {"; for (int i = 0; i < N; i++) cerr << (i ? "," : ""), print(arr[i]); cerr << "}]\n"; }
}
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
// TRIE
{
    #include<bits/stdc++.h>
    using namespace std;
    class Trie;
    class Node {

    private:
        char data;
        unordered_map<char,Node*> children;
        bool isTerminal;
        int complete=0;
        int prefix=0;

    public:
        Node(char d)
        {
            data=d;
            isTerminal=false;
            prefix=1;
            complete=0;
        }
        friend class Trie;
    };


    class Trie {
    private : 
        Node* root;
    public :
        Trie()
        {
            root= new Node('\0');
        }

        //Insertion

        void insert(string str)
        {
            Node* it=root;
            for(int i=0;i<str.size();i++)
            {
                auto add=it->children.find(str[i]);   
                if(add==it->children.end())//not found
                {
                    Node* ele= new Node(str[i]);
                    it->children.insert({str[i],ele});
                    it=ele;
                }
                else// if element is already present
                {   
                    it->prefix++;
                    it=add->second;
                }
            }
            it->isTerminal=true;
            it->complete++;
        }
        // Search
        bool search(string str)
        {
            Node* it=root;
            for(int i=0;i<str.size();i++)
            {
                auto add=it->children.find(str[i]);
                if(add==it->children.end())//not found
                {
                    return false;
                }
                else// if element is already present
                {   
                    it=add->second;
                }
            }
            return it->isTerminal;
        }
        //  complete exact string
        int numberOfString(string str)
        {
            Node* it=root;
            for(int i=0;i<str.size();i++)
            {
                auto add=it->children.find(str[i]);
                if(add==it->children.end())//not found
                {
                    return 0;
                }
                else// if element is already present
                {   
                    it=add->second;
                }
            }
            return it->complete;
        }
    };
}
// LPS
{
vi LPS(string arr)
{
    ll n=arr.size();
    vi lps(n,0);
    ll prev=0;
    ll i=1;
    while(i<n)
    {
        if(arr[i]==arr[prev])
        {
            prev++;
            lps[i]=prev;
            i++;
        }
        else
        {
            if(prev!=0)// most crucial point
            {
                prev=lps[prev-1];
            }
            else
            {
                i++;
            }
        }
    }
    return lps;
}
ll kmp(string arr, string pattern)
{
    ll n=arr.size();
    ll m=pattern.size();
    vi lps=LPS(pattern);

    ll count=0;
    ll prev=0;
    ll i=0;
    ll ans=0;
    while(i<n)
    {
        if(arr[i]==pattern[prev])
        {
            prev++;
            ans=prev;
            i++;
            if(ans==m)
            {
                count++;
                prev=m-1;
            }
        }
        else
        {
            if(prev==0)
            {
                ans=0;
                i++;
            }
            else
            {
                prev=lps[prev-1];
            }
        }
    }
    return  count;
}
}
// Z-array
{
    vi  getZarr(string str)
    {
        ll n = str.length();
        vi  Z(n);
        ll L, R, k;
        L = R = 0;
        for (ll i = 1; i < n; ++i)
        {
            if (i > R)
            {
                L = R = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
            else
            {
                k = i-L;
                if (Z[k] < R-i+1)
                    Z[i] = Z[k];
                else
                {
                    L = i;
                    while (R<n && str[R-L] == str[R])
                        R++;
                    Z[i] = R-L;
                    R--;
                }
            }
        }
        return Z;
    }
}
// TRIE
{
    #include<bits/stdc++.h>
    using namespace std;
    class Trie;
    class Node {

    private:
        char data;
        unordered_map<char,Node*> children;
        bool isTerminal;

    public:
        Node(char d)
        {
            data=d;
            isTerminal=false;
        }
        friend class Trie;
    };


    class Trie {
    private : 
        Node* root;
    public :
        Trie()
        {
            root= new Node('\0');
        }

        //Insertion

        void insert(string str)
        {
            Node* it=root;
            for(int i=0;i<str.length();i++)
            {
                auto add=it->children.find(str[i]);   
                if(add==it->children.end())//not found
                {
                    Node* ele= new Node(str[i]);
                    it->children.insert({str[i],ele});
                    it=ele;
                }
                else// if element is already present
                {   
                    it=add->second;
                }
            }
            it->isTerminal=true;
        }

        // Search

        bool search(string str)
        {
            Node* it=root;
            for(int i=0;i<str.length();i++)
            {
                auto add=it->children.find(str[i]);
                if(add==it->children.end())//not found
                {
                    return false;
                }
                else// if element is already present
                {   
                    it=add->second;
                }
            }
            return it->isTerminal;
        }

    };
}
// Rabin Karp Count
{
    ll Rabin_Karp_Count(string &arr, string &pattern)
    {
        ll n=arr.size();
        ll l=0,r=pattern.size()-1;
        ll pHash=0;
        ll cHash=0;
        ll p=1;ll previous_prime=1;
        ll count=0;
        REP(i,0,pattern.size())
        {
            ll current=((pattern[i]-'a'+1)*p)%MOD;
            pHash=(pHash+current)%MOD;
            ll curr=((arr[i]-'a'+1)*p)%MOD;
            cHash=(cHash+curr)%MOD;
            if(i!=pattern.size()-1)
            p=(p*31)%MOD;
        }
        while(r<n)
        {
            if(cHash==pHash)
            {
                count++;
            }
            l++;
            r++;
            p=(p*31)%MOD;
            if(r>=n)
            break;

            cHash=(cHash-((arr[l-1]-'a'+1)*previous_prime)%MOD+MOD)%MOD;
            cHash=(cHash+((arr[r]-'a'+1)*p)%MOD)%MOD;
            pHash=(31*pHash)%MOD;
            previous_prime=(previous_prime*31)%MOD;
        }
        return count;

    }
}
// Hashing
{
    // XOR Hashing
    //https://codeforces.com/contest/2014/submission/283519199
    {
        long long rng() {
        static std::mt19937 gen(
                std::chrono::steady_clock::now().time_since_epoch().count());
            return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
        }
    }
    {
        ll rollingHashFunction(string arr)
        {
            ll n=arr.size();
            ll MOD=(ll)(1e9+7);
            ll p=31;
            ll prime=p;
            ll hash=0;
            REP(i,0,n)
            {
                ll current=((arr[i]-'a'+1)*prime)%MOD;
                hash=(hash+current)%MOD;
                prime=(prime*p)%MOD;
            }
            return hash;
        }
    }
}
// Number Theory Abhishek Kumar Tamrakar
{
    {
        ll log_a_to_base_b(ll a, ll b)
        {
            return log2(a) / log2(b);
        }
        ll gcd( ll a, ll b)
        {
        if (b == 0)
            return a;
        return gcd(b, a % b);
        }
        // Function to return LCM of two numbers
        ll lcm(ll a, ll b)
        {
            return (a / gcd(a, b)) * b;
        }
    }
    ll maxn = 1e6+1;
    vector<ll> lp(maxn,0);
    void sieve()
    {
        lp[1] = 1;
        for(ll i = 2 ; i<maxn ; ++i)
        {
            if(!lp[i])
            {
                lp[i] = i;
                for(ll j=i*i ; j<maxn ; j+=i)
                {   
                    if(!lp[j]) lp[j] = i;
                }   
            }
        }
    }
    vector<bool> sieve_mobius(ll n,vi& um)
    {
        um = vi(n+1,1);
        vector<bool> primes(n+1,true);
        primes[1] = 0;
        REP(i,2,n+1)
        {
            if(primes[i])
            {
                for(int j = i ;j<=n;j+=i)
                {
                    if(j>i) primes[j] = 0;
                    if(j%(i*i)==0) um[j] = 0;
                    um[j] = -um[j];
                }
            }
        }
        return primes;
    }
}
// Monotonic Stack
{
    vi nextSmallerRight(vi&arr)
    {
        int n = arr.size();
        vi res(n,LONG_LONG_MAX);
        stack<ll> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty())
            {
                ll top = s.top();
                if(arr[top] >= arr[i])
                {
                    s.pop();
                }
                else
                {
                    res[i] = top;
                    break;
                }
            }
            if(res[i] == LONG_LONG_MAX)
            {
                res[i] = n;
            }
            s.push(i);
        }
        // debug(res);
        return res;
    }
    vi nextSmallerLeft(vi&arr)
    {
        int n = arr.size();
        vi res(n,LONG_LONG_MAX);
        stack<ll> s;
        REP(i,0,n)
        {
            while(!s.empty())
            {
                ll top = s.top();
                if(arr[top] >= arr[i])
                {
                    s.pop();
                }
                else
                {
                    res[i] = top;
                    break;
                }
            }
            if(res[i] == LONG_LONG_MAX)
            {
                res[i] = -1;
            }
            s.push(i);
        }
        // debug(res);
        return res;
    }
}
// Sati
{
    #include <bits/stdc++.h>
    // kruskal
    int get(int a, vector<int> &component)
    {
    return component[a] = (component[a] == a ? a : get(component[a], component));
    }
    void merge(int a, int b, vector<int> &rank, vector<int> &component)
    {
    a = get(a, component);
    b = get(b, component);
    if (a == b)
    return;
    if (rank[a] == rank[b])
    rank[a]++;
    if (rank[a] > rank[b])
    component[b] = a;
    else
    component[a] = b;
    }

    void solve()
    {

    int n, m;
    cin >> n >> m;
    vector<int> component(n);
    for (int i = 0; i < n; i++)
    {
    component[i] = i;
    }
    vector<int> rank(n, 0);
    vector<pair<ll, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    vector<pair<pair<int, int>, ll>> ans;
    for (auto i : edges)
    {
    if (sz(ans) == n - 1)
    break;
    int a = i.ss.ff;
    int b = i.ss.ss;
    if (get(a, component) != get(b, component))
    {
    merge(a, b, rank, component);
    ans.push_back({{min(a, b), max(b, a)}, i.ff});
    }
    }
    for (auto i : ans)
    {
    cout << i.ff.ff << " " << i.ff.ss << " " << i.ss << endl;
    }
    }

    //topological sort

    void topological_sort(int node, int &cnt)
    {
    queue<int> q;
    for (int i = 1; i <= node; i++)
    {
    if (indegree[i] == 0)
    {
    q.push(i);
    }
    }
    while (!q.empty())
    {
    cnt++;
    int current_node = q.front();
    order.push_back(current_node);
    q.pop();
    for (auto i : adj[current_node])
    {
    indegree[i]--;
    if (indegree[i] == 0)
    {
        q.push(i);
    }
    }
    }
    }

    //dijkstra
    void Dijkstra(int s, int n, vector<ll> &dist, vector<int> &parent, vector<pair<int, ll>> *adj)
    {
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while (!q.empty())
    {
    pair<ll, int> here = q.top();
    q.pop();
    int v = here.ss;
    ll d_v = here.ff;
    if (d_v != dist[v])
    continue;
    for (auto edge : adj[v])
    {
    if (dist[v] + edge.ss < dist[edge.ff])
    {
        dist[edge.ff] = dist[v] + edge.ss;
        parent[edge.ff] = v;
        q.push({dist[edge.ff], edge.ff});
    }
    }
    }
    }

    //floyd marshall
    void FloydWarshall(int n, vector<pair<int, ll>> *adj, vector<vector<ll>> &dist)
    {
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
    {
    dist[i][j] = INF;
    }
    dist[i][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
    for (auto j : adj[i])
    {
    dist[i][j.ff] = min(dist[i][j.ff], j.ss);
    }
    }
    for (int k = 0; k < n; k++)
    {
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
    {
        if (dist[i][k] < INF && dist[k][j] < INF) // for updating only when there is a path
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    }
    }
    }

    //bellman ford
    void BellmanFord(int n, int src, vector<pair<int, ll>> *edges, vector<ll> &dist, set<int> &negCycle)
    {
    fill(all(dist), INF);
    dist[src] = 0;
    vector<pair<ll, pair<int, int>>> e;
    for (int i = 0; i < n; i++)
    {
    for (auto j : edges[i])
    {
    e.pb({j.ss, {i, j.ff}});
    }
    }
    for (int i = 0; i < n - 1; i++)
    {
    for (auto j : e)
    {
    dist[j.ss.ss] = min(dist[j.ss.ss], dist[j.ss.ff] + j.ff);
    }
    }
    // checking negative cycle
    for (int i = 0; i < n; i++)
    {
    for (auto j : e)
    {
    if (dist[j.ss.ss] > dist[j.ss.ff] + j.ff)
    {
        dist[j.ss.ss] = dist[j.ss.ff] + j.ff;
        negCycle.insert(j.ss.ss);
    }
    }
    }
    }


    // kasaraju
    bool isPath(int src, int des, vector<vector<int>> &adj)
    {
    vector<int> vis(adj.size() + 1, 0);
    return dfs(src, des, adj, vis);
    }
    vector<vector<int>> findSCC(int n,vector<vector<int>> &a)
    { vector<vector<int>> ans;
    vector<int> is_scc(n + 1, 0);

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < a.size(); i++)
    {
    adj[a[i][0]].push_back(a[i][1]);
    }

    // Traversing all the vertices
    for (int i = 1; i <= n; i++)
    {

    if (!is_scc[i])
    {
    vector<int> scc;
    scc.push_back(i);

    for (int j = i + 1; j <= n; j++)
    {
        if (!is_scc[j] && isPath(i, j, adj) && isPath(j, i, adj))
        {
        is_scc[j] = 1;
        scc.push_back(j);
        }
    }
    ans.push_back(scc);
    }
    }
    return ans;
    }

    // segment tree

    template <typename Node, typename Update>
    struct SegTree
    {
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a)
    { // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < 2 * n)
    {
    s = s << 1;
    }
    tree.resize(s);
    fill(all(tree), Node());
    build(0, n - 1, 1);
    }
    void build(int start, int end, int index) // Never change this
    {
    if (start == end)
    {
    tree[index] = Node(arr[start]);
    return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) // Never Change this
    {
    if (start == end)
    {
    u.apply(tree[index]);
    return;
    }
    int mid = (start + end) / 2;
    if (mid >= query_index)
    update(start, mid, 2 * index, query_index, u);
    else
    update(mid + 1, end, 2 * index + 1, query_index, u);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
    if (start > right || end < left)
    return Node();
    if (start >= left && end <= right)
    return tree[index];
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index, left, right);
    r = query(mid + 1, end, 2 * index + 1, left, right);
    ans.merge(l, r);
    return ans;
    }
    void make_update(int index, ll val)
    {                                 // pass in as many parameters as required
    Update new_update = Update(val); // may change
    update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right)
    {
    return query(0, n - 1, 1, left, right);
    }
    };

    struct Node1
    {
    ll val; // may change
    Node1()
    {         // Identity element
    val = 0; // may change
    }
    Node1(ll p1)
    {          // Actual Node
    val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r)
    {                     // Merge two child nodes
    val = l.val ^ r.val; // may change
    }
    };

    struct Update1
    {
    ll val; // may change
    Update1(ll p1)
    {          // Actual Update
    val = p1; // may change
    }
    void apply(Node1 &a)
    {             // apply update to given node
    a.val = val; // may change
    }
    };


    // lazy segment tree

    template <typename Node, typename Update>
    struct LazySGT
    {
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<ll> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<ll> &a)
    { // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < 2 * n)
    {
    s = s << 1;
    }
    tree.resize(s);
    fill(all(tree), Node());
    lazy.resize(s);
    fill(all(lazy), false);
    updates.resize(s);
    fill(all(updates), Update());
    build(0, n - 1, 1);
    }
    void build(int start, int end, int index)
    { // Never change this
    if (start == end)
    {
    tree[index] = Node(arr[start]);
    return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end)
    {
    if (lazy[index])
    {
    int mid = (start + end) / 2;
    apply(2 * index, start, mid, updates[index]);
    apply(2 * index + 1, mid + 1, end, updates[index]);
    updates[index] = Update();
    lazy[index] = 0;
    }
    }
    void apply(int index, int start, int end, Update &u)
    {
    if (start != end)
    {
    lazy[index] = 1;
    updates[index].combine(u, start, end);
    }
    u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update &u)
    { // Never Change this
    if (start > right || end < left)
    return;
    if (start >= left && end <= right)
    {
    apply(index, start, end, u);
    return;
    }
    pushdown(index, start, end);
    int mid = (start + end) / 2;
    update(start, mid, 2 * index, left, right, u);
    update(mid + 1, end, 2 * index + 1, left, right, u);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
    if (start > right || end < left)
    return Node();
    if (start >= left && end <= right)
    {
    pushdown(index, start, end);
    return tree[index];
    }
    pushdown(index, start, end);
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index, left, right);
    r = query(mid + 1, end, 2 * index + 1, left, right);
    ans.merge(l, r);
    return ans;
    }
    void make_update(int left, int right, ll val)
    {                                 // pass in as many parameters as required
    Update new_update = Update(val); // may change
    update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right)
    {
    return query(0, n - 1, 1, left, right);
    }
    };

    struct Node1
    {
    ll val; // may change
    Node1()
    {         // Identity element
    val = 0; // may change
    }
    Node1(ll p1)
    {          // Actual Node
    val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r)
    {                     // Merge two child nodes
    val = l.val + r.val; // may change
    }
    };

    struct Update1
    {
    ll val; // may change
    Update1()
    { // Identity update
    val = 0;
    }
    Update1(ll val1)
    { // Actual Update
    val = val1;
    }
    void apply(Node1 &a, int start, int end)
    {                                 // apply update to given node
    a.val = val * (end - start + 1); // may change
    }
    void combine(Update1 &new_update, int start, int end)
    {
    val = new_update.val;
    }
    };

    // Bipartiatte
    const int MAXN1 = 50000;
    const int MAXN2 = 50000;
    const int MAXM = 150000;
    int n1, n2, edges, last[MAXN1], prev[MAXM], head[
    MAXM];
    int matching[MAXN2], dist[MAXN1], Q[MAXN1];
    bool used[MAXN1], vis[MAXN1];
    void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
    }
    void addEdge(int u, int v) {
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
    }
    void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
    if (!used[u]) {
    Q[sizeQ++] = u;
    dist[u] = 0;
    }
    }
    for (int i = 0; i < sizeQ; i++) {
    int u1 = Q[i];
    for (int e = last[u1]; e >= 0; e = prev[e]) {
    int u2 = matching[head[e]];
    if (u2 >= 0 && dist[u2] < 0) {
    dist[u2] = dist[u1] + 1;
    Q[sizeQ++] = u2;
    }
    }
    }
    }
    bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prev[e]) {
    int v = head[e];
    int u2 = matching[v];
    if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1
    ] + 1 && dfs(u2)) {
    matching[v] = u1;
    used[u1] = true;
    return true;
    }
    }
    return false;
    }
    int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
    bfs();
    fill(vis, vis + n1, false);ll depth[200005];
}
{
    // Stress Testing
    struct testcase
    {ll n,k;};
    ll randomNumber(ll a, ll b)
    {return a + (rand() % b);}
    // Function to generate a random number between l and r
    ll ran(ll l, ll r)
    {return l + (rand() % (r - l + 1));}
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
    testcase generateTestCase()ll depth[200005];
}
}
// LCA 
{
    ll depth[200005];
    ll lca[32][200005];
    void depth_compute(vvi&adj,ll node,ll parent){
        for(auto x : adj[node]){
            if(x != parent){
                depth[x] = depth[node] + 1;
                depth_compute(adj,x,node);
            }
        }
    }
    void lca_compute(vvi&adj,ll node,ll parent){
        lca[0][node] = parent;
        REP(i,1,33){
            lca[i][node] = lca[i-1][lca[i-1][node]];
        }
        for(auto x : adj[node]){
            if(x != parent) lca_compute(adj,x,node);;
        }
    }
    ll kth_ancestor(ll n,ll k)
    {
        if(k == 0){
            return lca[0][n];
        }
        if((k&(k-1))== 0){
            return lca[(int)log2(k)][n];
        }
        for(int i = 31;i>=0;i--){ 
            ll mask = 1<<i;
            if((k&mask) == mask){// if kth bit is set
                return kth_ancestor(lca[i][n],k-mask);
            }
        }
    }
    ll lca_query(ll a,ll b){
        ll depthA = depth[a];
        ll depthB = depth[b];
        if(depthA < depthB){
            b = kth_ancestor(b,depthB-depthA);
        }
        else if(depthA>depthB){
            a = kth_ancestor(a,depthA-depthB);
        }
        if(a == b)
        return a;
    
        for(int i=31;i>=0;i--)
        {
            if(lca[i][a] != lca[i][b])
            {
                a = lca[i][a];
                b = lca[i][b];
            }
        }
        return kth_ancestor(a,1);
    }
}