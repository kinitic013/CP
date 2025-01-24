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
ll n;
vector<set<ll>> adj;
vi status;
vi res;
vector<pair<char,pii>> Queries;
ll const THRESHOLD = 500;
void add_friend(ll u,ll v)
{
    adj[u].insert(v);
    adj[v].insert(u);
}
void remove_friend(ll u,ll v)
{
    adj[u].erase(v);
    adj[v].erase(u);
}
// void process_queries_for_answer(pair<char,pii>& x , ll target,ll& answer)
// {
//     char type = x.first;
//     ll val1 = x.second.first;
//     ll val2 = x.second.second;
//     if(type == 'O')
//     {
//         // status[val1] = 1;
//         auto it = adj[target].find(val1);
//         if(it != adj[target].end())
//         {
//             answer++;
//         }
//     }
//     else if(type == 'F')
//     {
//         // status[val2] = 0;
//         auto it = adj[target].find(val1);
//         if(it != adj[target].end())
//         {
//             answer--;
//         }
//     }
//     else if(type == 'A')// add Friend 
//     {
//         // add_friend(val1,val2);
//         if(val1 == target)
//         {
//             if(status[val2])
//             {
//                 answer++;
//             }
//         }
//         if(val2 == target)
//         {
//             if(status[val1])
//             {
//                 answer++;
//             }
//         }
//     }
//     else if(type == 'D')
//     {
//         // remove_friend(val1,val2);
//         if(val1 == target)
//         {
//             if(status[val2])
//             {
//                 answer--;
//             }
//         }
//         if(val2 == target)
//         {
//             if(status[val1])
//             {
//                 answer--;
//             }
//         }
//     }
//     else
//     {
//         // call queries are handled on the way
//     }
// }
// void rebuild()
// {
//     // // process queries to rebuild graph
//     // {
//     //     for(auto x : Queries)
//     //     {
//     //         char type = x.first;
//     //         ll val1 = x.second.first;
//     //         ll val2 = x.second.second;
//     //         if(type == 'O')
//     //         {
//     //             status[val1] = 1;
//     //         }
//     //         else if(type == 'F')// add Friend 
//     //         {
//     //             status[val1] = 0;
//     //         }
//     //         else if(type == 'A')// add Friend 
//     //       void process_queries_for_answer(pair<char,pii>& x , ll target,ll& answer)
// {
//     char type = x.first;
//     ll val1 = x.second.first;
//     ll val2 = x.second.second;
//     if(type == 'O')
//     {
//         // status[val1] = 1;
//         auto it = adj[target].find(val1);
//         if(it != adj[target].end())
//         {
//             answer++;
//         }
//     }
//     else if(type == 'F')
//     {
//         // status[val2] = 0;
//         auto it = adj[target].find(val1);
//         if(it != adj[target].end())
//         {
//             answer--;
//         }
//     }
//     else if(type == 'A')// add Friend 
//     {
//         // add_friend(val1,val2);
//         if(val1 == target)
//         {
//             if(status[val2])
//             {
//                 answer++;
//             }
//         }
//         if(val2 == target)
//         {
//             if(status[val1])
//             {
//                 answer++;
//             }
//         }
//     }
//     else if(type == 'D')
//     {
//         // remove_friend(val1,val2);
//         if(val1 == target)
//         {
//             if(status[val2])
//             {
//                 answer--;
//             }
//         }
//         if(val2 == target)
//         {
//             if(status[val1])
//             {
//                 answer--;
//             }
//         }
//     }
//     else
//     {
//         // call queries are handled on the way
//     }
// }
// void rebuild()
// {
//     // // process queries to rebuild graph
//     // {
//     //     for(auto x : Queries)
//     //     {
//     //         char type = x.first;
//     //         ll val1 = x.second.first;
//     //         ll val2 = x.second.second;
//     //         if(type == 'O')
//     //         {
//     //             status[val1] = 1;
//     //         }
//     //         else if(type == 'F')// add Friend 
//     //         {
//     //             status[val1] = 0;
//     //         }
//     //         else if(type == 'A')// add Friend 
//     //         {
//     //             add_friend(val1,val2);
//     //             // should we update res as new nodes are added
//     //         }
//     //         else if(type == 'D')
//     //         {
//     //             remove_friend(val1,val2);
//     //         }
//     //         else
//     //         {
//     //             // call queries are handled on the way
//     //         }
//     //     }
//     // }
//     // rebuilding after processing queries
//     res = vi(n+1,0);
//     {
//         REP(i,1,n+1)
//         {
//             if(!status[i])
//             continue;

//             auto it = adj[i].begin();
//             while(it != adj[i].end())
//             {
//                 res[*it]++;
//                 it++;
//             }
//         }
//     }
//     Queries = vector<pair<char,pii>>(0);
// }
//   {
//     //             add_friend(val1,val2);
//     //             // should we update res as new nodes are added
//     //         }
//     //         else if(type == 'D')
//     //         {
//     //             remove_friend(val1,val2);
//     //         }
//     //         else
//     //         {
//     //             // call queries are handled on the way
//     //         }
//     //     }
//     // }
//     // rebuilding after processing queries
//     res = vi(n+1,0);
//     {
//         REP(i,1,n+1)
//         {
//             if(!status[i])
//             continue;

//             auto it = adj[i].begin();
//             while(it != adj[i].end())
//             {
//                 res[*it]++;
//                 it++;
//             }
//         }
//     }
//     Queries = vector<pair<char,pii>>(0);
// }

void solve(ll t)
{
    ll m,q;cin>>n>>m>>q;
    adj.resize(n+1);
    res.resize(n+1,0);
    status.resize(n+1,0);

    ll o;cin>>o;
    REP(i,0,o)
    {
        ll ele;cin>>ele;
        status[ele] = 1;
    }
    REP(i,0,m)
    {
        ll u,v;cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);

        if(status[v])
        res[u]++;
        if(status[u])
        res[v]++;
    }

    REP(i,0,q)
    {
        char a;
        ll b=-1,c=-1;
        cin>>a>>b;
        if(a == 'O')
        {
            Queries.push_back({a,{b,c}});
            status[b] = 1;
        }
        else if(a == 'F')
        {
            Queries.push_back({a,{b,c}});
            status[b] = 0;
        }
        else if(a == 'A')
        {
            cin>>c;
            Queries.push_back({a,{b,c}});
            add_friend(b,c);
        }
        else if( a == 'D')
        {
            cin>>c;
            Queries.push_back({a,{b,c}});
            remove_friend(b,c);
        }
        else
        {
            if(Queries.size() >= THRESHOLD )
            {
                rebuild();
            }
            ll answer = res[b];
            REP(j,0,Queries.size())
            {
                process_queries_for_answer(Queries[j],b,answer);
            }
            cout<<answer<<"\n";
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