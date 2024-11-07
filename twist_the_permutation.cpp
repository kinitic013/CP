
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
int find(vi arr,int key)
{
    REP(j,0,arr.size())
    {
        if(arr[j]==key)
        {
            return j;
        }
    }
    return -1;
}
void Rshift(vi &arr, int key,int times)
{
    ll idx=times-1;
    int n=arr.size();
    times=times%key;
    vi temp;
    //shifted part
    REP(i,idx+1,key)
    {
        temp.pb(arr[i]);
    }
    REP(i,0,times)
    {
        temp.pb(arr[i]);
    }
    REP(i,key+1,n)
    {
        temp.pb(arr[i]);
    }
    arr=temp;
    return;

}
void  solve()
{
    int n;cin>>n;
    input
    vi result(n+1);
    for(int i=n;i>0;i--)
    {
        int idx=find(arr,i);
        result[i]=(idx+1)%i;
        if(result[i]!=0)
        Rshift(arr,i,idx+1);
    }
    REP(i,1,n+1)
    {
        cout<<result[i]<<" ";
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
