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
    string arr;
    cin>>arr;int n=arr.size();
    ll one=0,two=0,zero=0;
    vi idx,count;
    ll curr=0;
    REP(i,0,n)
    {
        if(arr[i]=='0')
        {
            zero++;
            curr++;
        }
        else if(arr[i]=='1')
        one++;
        else
        {
            two++;
            idx.pb(i);
            count.push_back(curr);
            curr=0;
        }
    }
    if(curr!=0)
    {
        idx.pb(-1);
        count.pb(curr);
        curr=0;
    }
    if(two==0)
    {
        sort(arr.begin(),arr.end());
        cout<<arr;
        return;
    }
    string result;
    REP(i,0,count[0])// all zero's before first 2
    result.pb('0');
    REP(i,0,one)// all one
    result.pb('1');
    result.pb('2');
    REP(i,1,idx.size())
    {
        REP(j,0,count[i])
        {
            result.pb('0');
        }
        if(idx[i]!=-1)
        result.pb('2');
    }
    cout<<result;
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
