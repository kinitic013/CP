#include<iostream>
#include<list>
#include<queue>
using namespace std;
 
class graph{
    int V;
    list<int> * l;

    void dsf_helper(int source,vector<bool> &visited)
    {
        for(auto nbr: l[source])
        {
            if(!visited[nbr])
            {
                visited[nbr]=true;
                cout<<nbr<<" ";
                dsf_helper(nbr,visited);
            }
        }
        return;
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

    void bfs(int source)
    {
        queue<int> q;
        vector<bool> visited(V,false);
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            //printing current top
            int f=q.front();
            cout<<f<<" ";
            q.pop();
            //if not visited push to to queue
            for(auto nbr:l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }

    }

    void dfs(int source)
    {
        vector<bool> visited(V,false);
        cout<<source<<" ";
        visited[source]=true;
        dsf_helper(source,visited);
        return;
    }

    void topoligical_order()
    {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto nbr:l[i])
            {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        //adding vertices with in_degree=0
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        //now getting work done
        //popping

        while(!q.empty())
        {
            int f=q.front();
            cout<<f<<" ";
            q.pop();
            //after gettin work done dependencies decreases
            for(auto nbr:l[f])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)// now if it turn out to be independent we push it in queue
                {
                    q.push(nbr);
                }
            }
        }
    }

};

int main()
{
    graph arr(6);
    arr.addEdge(1,2,false);
    arr.addEdge(1,4,false);
    arr.addEdge(2,3,false);
    arr.addEdge(3,5,false);
    arr.addEdge(4,5,false);
    arr.addEdge(0,2,false);
    arr.print();
    cout<<'\n';
    arr.bfs(1);
    cout<<'\n';
    arr.dfs(1);
    cout<<endl;
    arr.topoligical_order();
    return 0;
}