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
#define REP(i,a,b) for(ll i=a;i<b;i++)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    ll total=0;
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        if(ele==1)
        {
            total++;
        }
        arr.push_back(ele);
    }
    if(total<k)
    {
        cout<<-1;
        return;
    }
    ll s=0;
    ll e=0;
    ll maxi=0;ll sum=arr[0];ll size=1;
    bool flag=false;
    while(true)
    {
        if(sum<k)
        {
            e++;
            size++;
            if(arr[e]==1)
            {
                sum++;
                continue;
            }
            continue;
        }
        else if(sum==k)
        {
            if( e+1<n && arr[e+1]==0)
            {
                e++;
                size++;
                maxi=max(maxi,size);
            }
            else if(e+1<n && arr[e+1]!=0)
            {
                maxi=max(maxi,size);
                while(arr[s]!=1)
                {
                    s++;
                    size--;
                }
                s++;
                sum--;
                size--;
            }
            else
            {
                maxi=max(maxi,size);
                flag=true;
            }
        }
        if(flag)
        {
            break;
        }
    }
    cout<<(n-maxi);
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