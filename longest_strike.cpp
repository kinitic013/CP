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
    int n,k;cin>>n>>k;
    mii arr;
    REP(i,0,n)
    {
        int ele;
        cin>>ele;
        arr[ele]++;
    }
    auto it=arr.begin();
    ll maxi=0;ll curr=0;
    pii result; pii idx;
    ll last=it->ff-1;
    while(it!=arr.end())
    {
        if(it->ss>=k )
        {
            if(it->ff-last==1)
            {
                if(curr==0)
                {
                    idx.ff=it->ff;
                    idx.ss=it->ff;
                }
                idx.ss=it->ff;
                curr++;
            }
            else
            {
                if(curr>maxi)
                {
                    result=idx;
                    maxi=curr;
                }
                idx.ff=it->ff;
                idx.ss=it->ff;
                curr=1;
            }
        }
        else
        {

            if(curr>maxi)
            {
                result=idx;
                maxi=curr;
                curr=0;
            }
        }
        last=it->ff;
        it++;
    }
    if(curr>maxi)
    {
        result=idx;
        maxi=curr;
        curr=0;
    }
    if(result.ff==result.ss && result.ff==0)
    {
        cout<<-1;
        return;
    }
    cout<<result.ff<<" "<<result.ss;
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
