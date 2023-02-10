#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi seq;REP(i,0,n){ll ele;cin>>ele;seq.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
vector<vector<ll>> result;
vi val;
class graph{
    int V;
    list<int> * l;
    vi dsf_helper(int source,vector<bool> &visited)
    {
        
        ::val.pb(source);
        for(auto nbr: l[source])
        {
            if(!visited[nbr])
            {
                visited[nbr]=true;
                dsf_helper(nbr,visited);
            }
        }
        if(!val.empty())
        {   
            ::result.pb(val);
            ::val.clear();
        }
        return val;
    }
public:
    graph(int v)
    {
        V=v;// size/ Number of Nodes
        l=new list<int>[V];// creating an dynamically allocated array that store list<int> 
    }
    
    void addEdge(int i,int j, bool undir=true )// means connecting Node i and. j
    {
        l[i].push_back(j);
        if(undir)// if it's bidirectional than only we below step 
        {
            l[j].push_back(i);
        }   
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->>";
            for(int x:l[i])
            {
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
    void dfs(int source)
    {
        vector<bool> visited(V,false);
        visited[source]=true;
        dsf_helper(source,visited);
        return;
    }

};
void  solve()
{
    int n;cin>>n;
    vi seq;
    ll root_val;
    graph arr(n+1);
    seq.pb(0);
    REP(i,1,n+1)
    {
        int ele;cin>>ele;
        seq.pb(ele);
        if(ele==i)
        {
            root_val=ele;
        }
        else
        arr.addEdge(ele,i,false);
    }
    
    cout<<endl;
    arr.dfs(root_val);
    cout<<result.size()<<'\n';
    REP(i,0,result.size())
    {
        vi temp=result[i];
        cout<<temp.size()<<'\n';
        REP(j,0,temp.size())
        {
            cout<<temp[j]<<" ";
        }
        cout<<'\n';
    }
    result.clear();
    return ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
