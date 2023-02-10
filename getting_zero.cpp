#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<int,int>
#define pii pair<int,int>
#define vi vector<int>
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi arr;REP(i,0,n){int ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int n;cin>>n;
    input
    REP(i,0,n)
    {
        int result=INT_MAX;
        int count=0;
        int val=arr[i];
        if(val==0)
        {
            cout<<0<<" ";
            continue;
        }
        int pos=log2(val & -val) + 1;
        while(val!=32769)
        {
            result=min(result,16-pos+count);
            {
                //add
                val++;
                count++;
                pos=log2(val & -val) + 1;
                result=min(result,16-pos+count);
            }
            if(count>16)
            {
                break;
            }
        }
        cout<<result<<" ";

    }
    return ;
}
int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
