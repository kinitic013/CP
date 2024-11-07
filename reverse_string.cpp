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
bool rev(string arr,string target, ll idx,ll i)
{
    while(idx>=0 && i>=0 && i<target.size())
    {
        if(arr[idx]!=target[i])
        {
            return false;
        }
        idx--;
        i++;
    }
    if(i==target.size())
    {
        cout<<"YES";
        return true;
    }
    return false;
}
void  solve()
{
    string arr,target;cin>>arr>>target;
    int n=target.size();
    vi pos;
    REP(i,0,arr.size())
    {
        if(arr[i]==target[0])
        {
            pos.pb(i);
        }
    }
    ll i=0;
    REP(j,0,pos.size())
    {
        ll idx=pos[j];bool mark=0;i=0;
        while(idx<arr.size() && i<n)
        {   //moving forward
            if(target[i]==arr[idx] )
            {
                if(idx-1>=0 && i+1<n && target[i+1]==arr[idx-1])
                {
                    bool val=rev(arr,target,idx-1,i+1);
                    if(val)
                    {
                        return;
                    }
                }
                i++;idx++;
            }
            else
            {
                bool val=rev(arr,target,idx-2,i);
                if(val)
                {
                    return;
                }
                break;
            }
            if(idx==arr.size())
            {
                idx-=2;
                bool val=rev(arr,target,idx,i);
                if(val)
                {
                    return;
                }
                else
                {
                    break;
                }
            }
        }
        if(i==n)
        {
            cout<<"YES";
            return;
        }
    } 
    cout<<"NO";  
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
