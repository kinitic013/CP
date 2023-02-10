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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    string arr;
    string parity1;string parity2;
    ll odd=0,even=0;
    REP(i,0,n)
    {
        ll ele;cin>>ele;
        if(ele&1)
        {
            arr.pb('o');
            odd++;
        }
        else
        {
            arr.pb('e');
            even++;
        }
    }
    if(n==1)
    {
        cout<<0;
        return;
    }
    if(n%2!=0)//odd
    {
        if(abs(odd-even)!=1)
        {
            cout<<-1;return;
        }
        if(odd>even)
        {
            REP(i,0,n)
            {
                if(i%2==0)
                parity1.pb('o');
                else
                parity1.pb('e');
            }
            REP(i,0,n)
            {
                if(i%2==0)
                parity2.pb('o');
                else
                parity2.pb('e');
            }
        }
        else
        {
            REP(i,0,n)
            {
                if(i%2==0)
                parity1.pb('e');
                else
                parity1.pb('o');
            }
            REP(i,0,n)
            {
                if(i%2==0)
                parity2.pb('e');
                else
                parity2.pb('o');
            }
        }
    }
    else
    {
        if(abs(odd-even)!=0)
        {
            cout<<-1;return;
        }
        if(arr[0]=='o')
        {
            REP(i,0,n)
            {
                if(i%2==0)
                parity1.pb('o');
                else
                parity1.pb('e');
            }
            REP(i,0,n)
            {
                if(i%2==0)
                parity2.pb('e');
                else
                parity2.pb('o');
            }
        }
        else
        {
            REP(i,0,n)
            {
                if(i%2==0)
                parity1.pb('o');
                else
                parity1.pb('e');
            }
            REP(i,0,n)
            {
                if(i%2==0)
                parity2.pb('e');
                else
                parity2.pb('o');
            }
        }
    }
    ll i=0,j1=0,j2=0; ll val1=0,val2=0;
    char val=arr[0];ll count=0;
        while(i<n && j1<n)
        {
            if(arr[i]==val)
            {
                if(parity1[j1]==val)
                {
                    count+=(abs(i-j1));
                    i++;
                    j1++;
                }
                else
                {
                    j1++;
                }
                continue;
            }
            else
            i++;
        }
        val1=count;
        count=0; i=0;j2=0;
        while(i<n && j2<n)
        {
            if(arr[i]==val)
            {
                if(parity2[j2]==val)
                {
                    count+=(abs(i-j2));
                    i++;
                    j2++;
                }
                else
                {
                    j2++;
                }
                continue;
            }
            else
            i++;
        }
        val2=count;
        cout<<min(val1,val2);
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
