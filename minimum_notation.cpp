#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<int,int>
#define pii pair<int,int>
#define vi vector<int>
const int MOD = 1e9+7;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi arr;REP(i,0,n){int ele;cin>>ele;arr.pb(ele);}

//     REP(i,0,n)
//     {
//         int ele;
//         cin>>ele;
//         x.pb(ele);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    string list;
    cin>>list;
    int n=list.size();
    int mini=list[n-1]-'0';
    bool flag=0;
    for(int i=n-1;i>=0;i--)
    {
        if(list[i]-'0'<mini)
        {
            mini=list[i]-'0';
        }
        else if(list[i]-'0'>mini)
        {
            if(list[i]-'0'!=9)
            list[i]++;
        }
    }
    sort(list.begin(),list.end());
    cout<<list;
    return ;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}