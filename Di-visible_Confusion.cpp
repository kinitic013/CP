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
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
 
void  solve(vi &l)
{
    int n;cin>>n;input
    if(arr[0]%2==0)
    {
        cout<<"NO";
        return;
    }
    // first at index 2 remove all even numbers and at index 1 remove all odd number
    REP(i,0,min(n,25))
    {
        REP(j,2,23)
        {
            
        }
    }
    cout<<"YES";
    return ;
}
int main()
{
    vi l(25,0);
    l[1]=2;
    REP(i,2,25)
    {
        ll val=lcm(l[i-1],i+1);
        l[i]=val;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        solve(l);
        cout<<"\n";
    }
    return 0;
}