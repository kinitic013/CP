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
vector<long long> segTree;
vector<long long> lazySegTree;

// 
void build(vector<long long>& arr, long long start , long long end , long long index)
{
    if(start == end)
    {
        segTree[index] = arr[start];
        return; 
    }
    long long mid = (start + end)/2;
    long long left = index*2+1;
    long long right = index*2 + 2;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[index] = min(segTree[left],segTree[right]);
}
void rangeUpdate(vector<long long>& arr, long long start, long long end, long long index, long long l, long long r, long long value) {
    long long segTreeSize = segTree.size();
    long long left = index * 2 + 1;
    long long right = index * 2 + 2;
    long long mid = (start + end) / 2;

    // Apply pending lazy updates
    if (lazySegTree[index] != 0) {
        segTree[index] += lazySegTree[index];
        if (start != end) { // Propagate lazy value to children
            lazySegTree[left] += lazySegTree[index];
            lazySegTree[right] += lazySegTree[index];
        }
        lazySegTree[index] = 0;
    }

    // No overlap
    if (r < start || l > end) {
        return;
    }

    // Total overlap
    if (start >= l && end <= r) {
        segTree[index] += value;
        if (start != end) { // Update lazy for children
            lazySegTree[left] += value;
            lazySegTree[right] += value;
        }
        return;
    }

    // Partial overlap
    rangeUpdate(arr, start, mid, left, l, r, value);
    rangeUpdate(arr, mid + 1, end, right, l, r, value);
    segTree[index] = min(segTree[left], segTree[right]); // Update the current node
}

long long queryRange(long long start, long long end, long long index, long long l, long long r) {
    long long segTreeSize = segTree.size();
    long long left = index * 2 + 1;
    long long right = index * 2 + 2;
    long long mid = (start + end) / 2;

    // Apply pending lazy updates
    if (lazySegTree[index] != 0) {
        segTree[index] += lazySegTree[index];
        if (start != end) { // Propagate lazy value to children
            lazySegTree[left] += lazySegTree[index];
            lazySegTree[right] += lazySegTree[index];
        }
        lazySegTree[index] = 0;
    }

    // No overlap
    if (r < start || l > end) {
        return LONG_LONG_MAX;
    }

    // Total overlap
    if (start >= l && end <= r) {
        return segTree[index];
    }

    // Partial overlap
    long long leftValue = queryRange(start, mid, left, l, r);
    long long rightValue = queryRange(mid + 1, end, right, l, r);
    return min(leftValue, rightValue);
}

void solve(ll t)
{
    ll n;cin>>n;
    vi arr(n);
    REP(i,0,n) cin>>arr[i];

    ll q;cin>>q;
    segTree.resize(4*n,0);
    lazySegTree.resize(4*n,0);
    build(arr,0,n-1,0);
    REP(i,0,q)
    {
        ll l,r;cin>>l>>r;
        if(cin.peek() == '\n')
        {
            if(l<=r)
            {
                cout<<queryRange(0,n-1,0,l,r)<<"\n";
            }
            else
            {
                ll res1 = queryRange(0,n-1,0,0,r);
                ll res2 = queryRange(0,n-1,0,l,n-1);
                cout<<min(res1,res2)<<"\n";
            }
        }
        else
        {
            ll val;cin>>val;
            if(l<=r)
            {
                rangeUpdate(arr,0,n-1,0,l,r,val);
            }
            else
            {
                rangeUpdate(arr,0,n-1,0,0,r,val);
                rangeUpdate(arr,0,n-1,0,l,n-1,val);
            }

        }
    }
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