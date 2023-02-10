#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void helper_(vector<vector<char>> &arr,int k,int i,int j,int r,int c)
{
    return;
    for(;i<=(i+k);i++)
    {
        if (i != r)
        {
            for (; j <= (j + k); j++)
            {
                if(j!=c)
                {
                    arr[i][j]='X';
                    break;
                }

            }
        }
    } 
}
void helper(vector<vector<char>> &arr,int k,int i,int j)
{
    REP(m,1,k+1)
    {
        REP(n,1,k+1)
        {
            if(m-n==0)
            arr[i-k+m][j-k+n]='X';
            j++;
        }
        i++;
    }
}
void  solve()
{
    int n,k,c,r;
    cin>>n>>k>>r>>c;
    vector<vector<char>> arr;
    vector<char> t;
    arr.pb(t);
    REP(i,1,n+1)
    {
        vector<char> temp;
        temp.pb(0);
        REP(j,1,n+1)
        {
            temp.pb('.');
        }
        arr.pb(temp);
    }
    arr[r][c]='X';
    bool flag=false;
    for(int i=k;i<n+1;i+=k)
    {
        for(int j=k;j<n+1;j+=k)
        {
            if(r<=i && c<=j && !flag)
            {
                helper_(arr,k,i,j,r,c);
            }
            else
            {
                helper(arr,k,i,j);
            }
            
        }
    }
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