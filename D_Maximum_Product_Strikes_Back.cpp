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
// void solve()
// {
//     ll n;cin>>n;
//     vvi arr;
//     vi number;
//     vi temp;
//     vi start;
//     bool flag= 1;
//     REP(i,0,n)
//     {
//         ll ele;cin>>ele;
//         number.pb(ele);
//         if(ele)
//         {
//             if(flag)
//             {
//                 start.pb(i);
//                 flag = 0;
//             }
//             temp.pb(ele);
//         }
//         else
//         {
//             if(!temp.empty())
//             {
//                 flag = 1;
//                 arr.pb(temp);
//                 temp = vi();
//             }
//         }
//     }
//     if(!temp.empty())
//     {
//         arr.pb(temp);
//         temp = vi();
//     }


//     n  = arr.size();
//     if(n==0)
//     {
//         cout<<0<<" "<<number.size();
//         return;
//     }
//     vvi pre(n);
//     vvi post(n);
//     vi count(n);
//     ll ans = 0;
//     ll idx = -1;
//     pii range = {0,0};
//     REP(i,0,arr.size())
//     {
//         ll product = 1;
//         for(auto x : arr[i])
//         {
//             product *= x;
//             if(x<0)
//             count[i]++;

//             pre[i].pb(product);
//         }

//         product = 1;

//         for(int j=arr[i].size()-1;j>=0;j--)
//         {
//             product*= arr[i][j];
//             post[i].pb(product);
//         }
//         reverse(all(post[i]));
//         debug(i,arr[i],pre[i],post[i],ans,idx,range);
//         if(count[i]%2==0)
//         {
//             if(pre[i][pre[i].size()-1] > ans)
//             {
//                 ans = pre[i][pre[i].size() - 1];
//                 idx = i;
//                 range = {0,0};
//             }
//         }
//         else
//         {
//             ll low = 0;
//             ll high = pre[i].size() - 1;
//             while(pre[i][low]>0)
//             low++;
//             while(post[i][high]>0)
//             high--;

//             ll val_after_low = (pre[i][pre[i].size()-1])/(pre[i][low]);
//             ll val_after_high = (high-1 >=0 ) ? pre[i][high-1] : 1;
//             if(val_after_high >= val_after_low && val_after_high > ans)
//             {
//                 idx = i;
//                 range  = {0,pre[i].size() - high};
//             }
//             else if(val_after_low >= val_after_high && val_after_low > ans)
//             {
//                 idx = i;
//                 range = {low + 1,0};
//             }
//         }
//     }
//     ll low = range.ff + start[idx];
//     ll high = range.ss + (number.size() -  (start[idx] + arr[idx].size()));
//     debug(ans,idx,range);
//     cout<<low<<" "<<high;
// }

void solve()
{
    ll n ;cin>>n;
    vi arr(n);
    vvi adj;
    bool flag = 1;
    REP(i,0,n)
    {
        cin>>arr[i];
        if(arr[i] == 0)
        {
            flag=1;
            adj.pb({0});
        }
        else
        {
            if(flag)
            {
                adj.pb({arr[i]});
                flag = 0;
            }
            else
            {
                adj[adj.size()-1].pb(arr[i]);
            }
        }
    }    
    ll idx = -1;
    pii range = {0,0};
    ll ans = 0;
    REP(i,0,adj.size())
    {
        // vi temp;
        ll prod = 0;
        ll negatives = 0;
        REP(j,0,adj[i].size())
        {
            if(adj[i][j] < 0 )
            negatives ++;

            if(adj[i][j] == 2 || adj[i][j] == -2)
            prod++;
        }
        debug(arr[i],negatives,ans,range,idx);
        if(negatives&1)
        {
            ll left_prod = 0;
            ll right_prod = 0;
            ll left_count = 0;
            ll right_count = 0;
            REP(j,0,adj[i].size())
            {
                left_count++;
                if(adj[i][j] == 2 || adj[i][j] == -2)
                left_prod++;

                if(adj[i][j]<0)
                break;
            }
            for(int j=adj[i].size()-1;j>=0;j--)
            {
                right_count++;
                if(adj[i][j] == 2 || adj[i][j] == -2)
                right_prod++;

                if(adj[i][j]<0)
                break;
            }

            if((prod-left_prod)>=(prod-right_prod) && (prod-left_prod)>ans)
            {
                idx = i;
                range = {left_count,0};
                ans = (prod-left_prod);
            }
            else if((prod-right_prod)>=prod-left_prod && (prod-right_prod)>ans )
            {
                idx = i;
                range = {0,right_count};
                ans = (prod-right_prod);
            }
        }
        else
        {

            if(prod > ans)
            {
                idx = i;
                ans = prod;
                range = {0,0};
            }

        }

    }
    if(idx == -1)
    {
        cout<<0<<" "<<n;
        return;
    }
    pii result = {0,0};
    ll l = 0;
    ll h = 0;
    REP(i,0,adj.size())
    {
        if(i==idx)
        break;

        l += adj[i].size();
    }
    for(int i=adj.size()-1;i>=0;i--)
    {
        if(i==idx)
        break;

        h += adj[i].size();
    }

    cout<<l+range.first<<" "<<h+range.second;
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
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}