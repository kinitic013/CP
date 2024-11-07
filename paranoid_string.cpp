#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
//everysubstring that ends with 00 or 11 will never be paranoid and every other substring will any how turout to be paranoid
void  solve()
{
    ll n;
    cin>>n;
    string arr;
    cin>>arr;
    ll count=0;
    REP(i,0,n-1)
    {
        if(arr[i]==arr[i+1])
        {
            count+=(i+1);
        }
    }
    ll result=((n*(n+1))/2)-count;
    cout<<result;
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