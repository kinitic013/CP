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
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}

//     REP(i,0,n)
//     {
//         ll ele;
//         cin>>ele;
//         x.pb(ele);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void helper(string arr,vi &result,ll a,ll b,ll i,char val=0)
{
    if(i==10)
    {
        result.pb(10);
        return;
    }
    if(val!=0)
    {
        if(i%2==0)
        a++;
        else
        b++;
    }
    else if(arr[i]=='1')
    {
        if(i%2==0)
        a++;
        else
        b++;
    }
    else if(arr[i]=='?')
    {
        helper(arr,result,a,b,i,'1');
    }
    if(a>b)
    {
        if(i%2==0)
        {
            if(a-b>(10-i)/2)
            {
                result.pb(i+1);
                return;
            }
        }
        else 
        {
            if(a-b>(10-i)/2)
            {
                result.pb(i+1);
                return;
            }
        }
    }
    else if(b>a)
    {
        if(i%2==0)
        {
            if(b-a>(10-i)/2-1)
            {
                result.pb(i+1);
                return;
            }
        }
        else 
        {
            if(b-a>(10-i)/2)
            {
                result.pb(i+1);
                return;
            }
        }
    }
    helper(arr,result,a,b,i+1);
    return;
}
void  solve(string arr)
{
    ll a=0;ll b=0;
    vi result;

    helper(arr,result,a,b,0);
    cout<<*min_element(result.begin(),result.end());
    return;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string arr;
        cin>>arr;
        solve(arr);
        cout<<"\n";
    }
    return 0;
}