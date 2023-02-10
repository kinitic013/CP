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

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
// yet to handle n==1 and odd
void  solve()
{
    int a,b;cin>>a>>b;
    int n=a+b;
    string arr;
    cin>>arr;
    ll count=0;
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]==arr[j] && arr[i]=='?')
        {
            count++;
            i++;
            j--;
            continue;
        }
        else if(arr[i]==arr[j])
        {
            if(arr[i]=='0')
            {
                a-=2;
                if(a<0)
                {
                    cout<<-1;
                    return;
                }
            }
            else
            {
                b-=2;
                if(b<0)
                {
                    cout<<-1;
                    return;
                }
            }
            i++;
            j--;
            continue;
        }


        if(arr[i]!=arr[j] && (arr[i]!='?' && arr[j]!='?'))
        {
            cout<<-1;
            return;
        }
        else if(arr[i]!=arr[j])
        {
            if(arr[i]=='0' || arr[j]=='0')
            {
                a-=2;
                arr[i]='0';
                arr[j]='0';
                if(a<0)
                {
                    cout<<-1;
                    return;
                }
            }
            else if(arr[i]=='1' || arr[j]=='1')
            {
                b-=2;
                arr[i]='1';
                arr[j]='1';
                if(b<0)
                {
                    cout<<-1;
                    return;
                }
            }
            i++;
            j--;
            continue;
        }
    }
    if(n&1 )
    {
        if(arr[n/2]=='?')
        {
            if(a&1)
            {
                a--;
                arr[n/2]='0';
            }
            else if(b&1)
            {
                b--;
                arr[n/2]='1';
            }
        }
        else if(arr[n/2]=='1')
        {
            b-=1;
            if(b<0)
                {
                    cout<<-1;
                    return;
                }
        }
        else if(arr[n/2]=='0')
        {
            a-=1;
            if(a<0)
                {
                    cout<<-1;
                    return;
                }
        }
    }
    if((a/2)+(b/2)!=count)
    {
        cout<<-1;
        return;
    }
    i=0;j=n-1;
    while(i<=j)
    {
        if(arr[i]=='?')
        {
            if(a>=2)
            {
                arr[i]='0';
                arr[j]='0';
                a-=2;
            }
            else if(b>=2)
            {
                arr[i]='1';
                arr[j]='1';
                b-=2;
            }
            
        }
        i++;
        j--;
    }
    cout<<arr;
    return;
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