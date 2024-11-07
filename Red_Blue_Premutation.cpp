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
bool cmps(pair<int,char> a,pair<int,char> b)
{
    if(a.ss!=b.ss)
    {
        return a.ss<b.ss;
    }
    else
    {
        return a.ff<b.ff;
    }
}

void  solve()
{
    vector<pair<int,char>> arr;
    int n;cin>>n; vi seq;
    REP(i,0,n)
    {
        int ele;cin>>ele;
        seq.pb(ele);
    }
    string color;
    cin>>color;
    REP(i,0,n)
    {
        arr.pb({seq[i],color[i]});
    }
    sort(arr.begin(),arr.end(),cmps);
    vector<bool> done(n+1,false);
    for(int i=0;i<n;)
    {
        if(arr[i].ss=='B')
        {
            if(arr[i].ff>=i+1)
            {
                done[i+1]=true;
                i++;
            }
            else
            {
                cout<<"NO";
                return;
            }
        }
        else
        {
            
            if(arr[i].ff<=i+1)
            {
                done[i+1]=true;
                i++;
            }
            else
            {
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES";
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
