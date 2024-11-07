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
class Trie;
class Node {

private:
    char data;
    unordered_map<int,Node*> children;
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
    void insert(vi str)
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
                it=add->second;
            }
        }
        it->isTerminal=true;
    }
    // Search
    bool search(vi str)
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
};
vi inverse(vi& arr)
{
    int n =arr.size();
    vi res(n,-1);
    REP(i,0,n)
    {
        res[arr[i]] = i;
    }
    return res;
}

void solve(vi& p)
{
    int n ,m;cin>>n>>m;
    Trie T;
    vvi arr(n,vi(m));
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            cin>>arr[i][j];
            arr[i][j]--;
        }
        vi inv =  arr[i];
        vi array = inverse(arr[i]);
        arr[i] = array;
        T.insert(inv);
        REP(j,0,m-1)
        {
            int pos = -1, maxi = -1;
            REP(k,0,m)
            {
                if(inv[k] > maxi)
                {
                    maxi = inv[k];
                    pos = k;
                }
            }
            inv[pos] = -1;
            T.insert(inv); 
        }
    }
    REP(i,0,n)
    {
        int ans = 0;
        REP(j,0,m)
        {
            bool found = T.search(arr[i]);
            if(found)
            {
                ans = m-j;
                break;
            }
            int pos = -1, maxi = -1;
            REP(k,0,m)
            {
                if(arr[i][k] > maxi)
                {
                    maxi = arr[i][k];
                    pos = k;
                }
            }
            arr[i][pos] = -1;
        }
        cout<<ans<<" ";
    }
    return ;
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