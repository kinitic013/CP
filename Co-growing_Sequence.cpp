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

void  solve()
{
    int n;cin>>n;
    input
    vi result;
    result.pb(0);
    vi c;
    c.pb(arr[0]);
    ll len=log2(*max_element(arr.begin(),arr.end()))+1;
    REP(i,1,n)
    {
        ll val=c[i-1];
        ll ele=1;
        // changing "C"
        
        ll b=0;ll mask=0;
        ll j=0;
        while(j<len)
        {
            if(mask==0)
            mask=1;
            else
            mask*=2;

            ll temp1=mask&val;
            ll ele=arr[i];
            if(temp1==0)
            {
                ll temp2=(arr[i]&mask);
                if(temp2!=0)
                {
                    val+=mask;
                    j++;continue;
                }
            }
            else // if jth bit is one
            {
                ll temp=arr[i]&mask;
                if(temp==0)
                {
                    b+=mask;
                    j++;continue;
                }
            }
            j++;
        }
        result.pb(b);
        c.pb(val);
    }
    REP(i,0,result.size())
    {
        cout<<result[i]<<" ";
    }
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
