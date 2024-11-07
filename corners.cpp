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
/*
My Approach is->constraints allow N2 search
                To get Maximum operation we try to convert one 1 to 0 in one operation 
                that can happen if we have 2 zeros
                so in first operation we check wheather 2 consecutive or up-down or diagonal zeros are present
                    if yes
                        then with every operation 1 -> 0 is converted so no. of opearitons would be No. of one in matrix
                    else
                        if(all one)
                        {
                            then No. of one -2 would be answer
                            as in op 1. 3 one -> 0
                        }
                        else 
                        {
                            No. of one -1
                        }
*/
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int m,n;
    cin>>n>>m;
    vector<vector<char>> arr;
    int one=0;int zero=0;
    bool flag=false;
    bool corner_flag=false;
    REP(i,0,n)
    {
        vector<char> temp;
        REP(j,0,m)
        {
            char ele;
            cin>>ele;
            if(ele=='0')
            {
                zero++;
            }
            else
            one++;
            temp.push_back(ele);
        }
        arr.push_back(temp);
    }
    if(!one)
    {
        cout<<0;
        return;
    }
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            //checking for diagonal zeors
            if(arr[i][j]=='1')// bottom right
            {
                if(flag)
                {
                    break;
                }
                if(i+1<n && j+1<m)
                {
                    if(arr[i+1][j]=='0' && arr[i][j+1]=='0')
                    {
                        flag=true;
                        break;
                    }
                }
                if(i+1<n && j-1>=0)// bottom left
                {
                    if(arr[i+1][j]=='0' && arr[i][j-1]=='0')
                    {
                        flag=true;
                        break;
                    }
                }
                if(i-1>=0 && j+1<m)// top right
                {
                    if(arr[i-1][j]=='0' && arr[i][j+1]=='0')
                    {
                        flag=true;
                        break;
                    }
                }
                if(i-1>=0 && j-1>=0)// top left
                {
                    if(arr[i-1][j]=='0' && arr[i][j-1]=='0')
                    {
                        flag=true;
                        break;
                    }
                }

            }
            // checking for up-down or consecutive 
            if(arr[i][j]=='0' && i+1<n )
            {
                if(arr[i+1][j]=='0')
                {
                    flag=true;
                    break;
                }
            }
            if(arr[i][j]=='0' && j+1<m)
            {
                if(arr[i][j+1]=='0')
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
        {
            break;
        }
    }
    if(flag)
    {
        cout<<one;
        return;
    }
    else
    {
        if(zero)
        {
            cout<<one-1;
            return;
        }
        else
        {
            cout<<one-2;
            return;
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