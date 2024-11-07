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
#define MOD (long long)(1e9 + 7)
#define mod (long long)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
class Trie;
class Node {

public:
    int data;
    unordered_map<int,Node*> children;
    Node* parent = nullptr;
    bool isTerminal;

    Node(int d,Node*par)
    {
        data=d;
        isTerminal=false;
        parent = par;
    }
    friend class Trie;
};


class Trie {
private : 
    Node* root;
public :
    Trie()
    {
        root= new Node('\0',nullptr);
    }

    //Insertion

    void insert(vector<bool>& str)
    {
        Node* it=root;
        for(int i=0;i<str.size();i++)
        {
            auto add=it->children.find(str[i]);   
            if(add==it->children.end())//not found
            {
                Node* ele= new Node(str[i],it);
                it->children.insert({str[i],ele});
                it=ele;
            }
            else// if element is already present
            {   
                // it->prefix++;
                it=add->second;
            }
        }
        it->isTerminal=true;
    }

    // Search
    pair<bool,Node*> search(vector<bool>& str,int& idx)
    {
        Node* it=root;
        for(int i=0;i<str.size();i++)
        {
            auto add=it->children.find(str[i]);
            if(add==it->children.end())//not found
            {
                return {false,nullptr};
            }
            else// if element is already present
            {   
                it=add->second;
            }
        }
        // idx = it->idx;
        return {it->isTerminal,it};
    }
    // Ancestor
    bool isAncestor(Node*it)
    {
        bool res = false;

        if(it == nullptr)
        return false;
        if(it->isTerminal == true)
        return true;

        bool val = it->data;
        if(val == 0)
        {
            Node* next = it->parent;
            if(next == nullptr)
            return false;
            else
            {
                if(next->data == 1)
                res = res or false;
                else
                res = res or isAncestor(next->parent);

            }
        }
        else
        {
            Node* next = it->parent;
            res = res or isAncestor(next);
        }
        return res;
    }

};
vb decimal_to_string(int n)
{
    vb res;
    while(n)
    {
        res.pb((n&1));
        n/=2;
    }
    reverse(aint(res));
    return res;
}
vi dp(2e5+10,0);
void solve(int t)
{
    int n,p;cin>>n>>p;
    vi arr(n);
    Trie T;
    REP(i,0,n)
    {
        int ele;cin>>ele;
        arr[i] = ele;
    }
    sort(aint(arr));
    REP(i,0,n)
    {
        vb str = decimal_to_string(arr[i]);
        T.insert(str);
    }
    // vi dp(p+10,0);
    
    int ans = 0;

    REP(i,0,n)
    {
        vb bin = decimal_to_string(arr[i]);
        Node* ptr = T.search(bin,i).ss;
        bool check = false;
        if(ptr->data == 0)
        {
            Node* next = ptr->parent;
            if(next->parent != nullptr)
            {
                if(next->data == 1)
                check = false;
                else
                check = T.isAncestor(next->parent);

            }
        }
        else
        {
            Node * next = ptr->parent;
            check = T.isAncestor(next);
        }

        if(check)
        {
            continue;
        }
        else
        {
            int curr = 0;
            int val = p - bin.size();
            if(val>=0)
            curr = dp[val];

            ans = (ans + curr)%MOD;
        }
    }
    cout<<ans;
    return;
}
int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // int t;
    // cin >> t;
    // REP(T,1,t+1)
    dp[0] = 1;
    dp[1] = 1;

    REP(i,2,2e5+10)
    {
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }
    REP(i,1,2e5+10)
    {
        dp[i] = (dp[i] + dp[i-1])%MOD;
    }
    {
        solve(1);
        cout << endl;
    }
    return 0;
}