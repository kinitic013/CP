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
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

ll count=0;
class graph{
    int V;
    list<int> * l;

    pii dsf_helper(int source,vector<bool> &visited,string col)
    {
		pii val;
    	val.ff=0;
    	val.ss=0;
        for(auto nbr: l[source])
        {
            if(!visited[nbr])
            {
                visited[nbr]=true;
                pii temp=dsf_helper(nbr,visited,col);
				val.ff+=temp.ff;
             	val.ss+=temp.ss;
            }
        }
		if(col[source-1]=='B')
        val.ff++;
        else
        val.ss++;

        if(val.ff==val.ss)
        {
            ::count++;
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
	void dfs(int source,string col)
    {
        vector<bool> visited(V,false);
        visited[source]=true;
        dsf_helper(source,visited,col);
        return;
    }
};

void  solve()
{
    int n;cin>>n;
    graph arr(n+1);
	arr.addEdge(0,1,false);
    REP(i,2,n+1)
    {
        ll ele;
        cin>>ele;
		arr.addEdge(ele,i,false);
    }
    string col;cin>>col;
    ll b=0; ll w=0;
	arr.dfs(1,col);
    cout<<::count;
    ::count=0;
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







// pii helper(vi arr,vi &isvisited,string col,int i,ll b,ll w)
// {
//     pii val;
//     val.ff=0;
//     val.ss=0;
//     //base case
//     if(i==arr.size())
//     {
//         return  val;
//     }
//     //rec case
//     {

//         isvisited[i]=1;
//         REP(j,i+1,arr.size())
//         {
//             if(arr[j]==i+1 && isvisited[j]==0)
//             {
//                 pii temp=helper(arr,isvisited,col,j,b,w);
//                 val.ff+=temp.ff;
//                 val.ss+=temp.ss;
//             }
//         }

//         if(col[i]=='B')
//         val.ff++;
//         else
//         val.ss++;

//         if(val.ff==val.ss)
//         {
//             ::count++;
//         }
//         return val;
//     }
// }