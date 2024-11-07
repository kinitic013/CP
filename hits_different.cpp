#include <bits/stdc++.h>
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
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
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
ll dfs(vvi &adj , vb&visited , ll node )
{
    ll count = 0;
    if(visited[node])
    return count;
    visited[node]=1;
    count+= (node*node);
    auto it = adj[node].begin();
    while(it!=adj[node].end())
    {
        if(*it<node)
        {
            if(!visited[*it] )
                count+= dfs(adj,visited,*it );
        }
        it++;
    }
    return count;
}

void solve(vvi& adj , vector<pair<ll,pii>>&ans)
{
    ll n;cin>>n;
    cout<<ans[n].ff;
    return;
}
int main()
{
    fast();
    vvi adj(1e6+1);
    vector<pair<ll,pii>> ans(1e6+1);
    ll level = 2;
    pii prevRange= {1,1};
    ans[1]={1,{0,0}};
    REP(i,2,1e6+1)
    {
        pair<ll,pii> current={0,{0,0}};
        ll val = (level*(level+1))/2;
        ll prevLevel = level-1;
        ll childl = i-level;
        ll childr = i-prevLevel;
        bool l = false;
        bool r = false;


        if(childl<=prevRange.ss && childl>=prevRange.ff)
        {
            current.ss.ff = (childl*childl) + (ans[childl].ss.ff);    
            l = true;        
        }

        if(childr<=prevRange.ss && childr>=prevRange.ff)
        {
            current.ss.ss = (childr*childr) + (ans[childr].ss.ss);
            r = true;
        }

        if(r == true)
        {
            current.ff += ans[childr].ff;
            if(l == true)
            {
                current.ff += (childl*childl) + ans[childl].ss.ff;
            }
        }
        else if(l == true)
        {
            current.ff +=ans[childl].ff;
        }
        current.ff += i*i;
        ans[i] = current;

        if( i == val)
        {
            prevRange={i-level+1,i};
            level++;
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        solve(adj,ans);
        cout << endl;
    }
    return 0;
}
