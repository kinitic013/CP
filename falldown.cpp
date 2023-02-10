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
#define endl '\n'
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> matrix;
    vector<vector<char>> arr;
    REP(i,0,n)
    {
        string temp;
        cin>>temp;
        matrix.pb(temp);
    }
    REP(i,0,n)
    {
        vector<char> temp;
        REP(j,0,m)
        {
            temp.push_back(matrix[i][j]);
        }
        arr.pb(temp);
    }
    int idx;
    int s,e;
    REP(i,0,m)//seclecting column
    {
        idx=-1;
        REP(j,0,n)//searching over row for obstacle
        {
            if(arr[j][i]=='o')
            {
                if(idx==-1)
                s=idx+1;
                else
                s=idx+1;
                idx=j;
                e=idx-1;
                while (s < e && s<m && e>=0)
                {
                    if (arr[e][i] == 'o' || arr[e][i] == '*')
                    {
                        e--;
                        continue;
                    }
                    if (arr[s][i] != '*')
                    {
                        s++;
                        continue;
                    }
                    swap(arr[s][i], arr[e][i]);
                    s++;
                    e--;
                }
            }
        }
        if(idx==n-1)
        {
            continue;
        }
        // after obstacles are over in array
        {
            s = idx+1;
            e = n - 1;
            while (s < e && s < m && e >= 0)
            {
                if (arr[e][i] == 'o' || arr[e][i] == '*')
                {
                    e--;
                    continue;
                }
                if (arr[s][i] != '*')
                {
                    s++;
                    continue;
                }
                swap(arr[s][i], arr[e][i]);
                s++;
                e--;
            }

        }
    }
    REP(i,0,n)//row
    {
        REP(j,0,m)//colu
        {
            cout<<arr[i][j];
        }
        cout<<endl;
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