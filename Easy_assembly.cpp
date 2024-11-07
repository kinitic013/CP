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
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    int n;cin>>n;
    vector<vector<ll>> matrix;
    set<ll> arr;
    REP(i,0,n)
    {
        ll k;cin>>k;
        vi temp(k);
        REP(j,0,k)
        {
            cin>>temp[j];
            arr.insert(temp[j]);
        }
        matrix.pb(temp);
    }
    ll ele=0;
    ll s=0,c=0;
    REP(i,0,n)
    {
        ll k=matrix[i].size();
        ele++;
        REP(j,0,k-1)
        {
            auto it=arr.find(matrix[i][j]);
            if(it!=(--arr.end()))
            it++;
            else
            {
                s++;
                ele++;
                continue;
            }
            if(matrix[i][j+1]!=*it)
            {
                s++;
                ele++;
            }
            else
            {
                continue;
            }
        }
    }
    c=ele-1;
    cout<<s<<" "<<c;return;
}
int main()
{
    // ll t;
    // cin>>t;
    // while()
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
