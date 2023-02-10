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
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

bool  rev(pii time,pii &temp,vector<pii> conv)
{
    ll a,b,c,d;
    a=conv[time.ss%10].ss*10;
    time.ss/=10;
    b=conv[time.ss%10].ss;
    c=conv[time.ff%10].ss*10;
    time.ff/=10;
    d=conv[time.ff%10].ss;
    if(a<0 || b<0 || c<0 || d<0)
    {
        return false;
    }
    temp.ff=a+b;
    temp.ss=c+d;
    return true;
}
void  solve(vector<pii> &conv)
{
    int h,m;cin>>h>>m;
    string time;
    cin>>time;
    pii curr;
    curr.ff=(time[1]-'0'+(time[0]-'0')*10);
    curr.ss=(time[3]-'0'+(time[2]-'0')*10);
    while(1)
    {
        pii temp;
        bool flag=rev(curr,temp,conv);
        if(flag)
        {
            cout<<curr.ff<<" "<<curr.ss;
            //incomplete for preceding zero
            return;
        }
        else
        {
            curr.ss++;
            if(curr.ss==m)
            {
                m==0;
                curr.ff++;
            }
            if(curr.ff==h)
            {
                curr.ff=0;
            }
        }
    }
}
int main()
{
    vector<pii> conv;
    conv.pb({0,0});conv.pb({1,1});conv.pb({2,5});conv.pb({3,-1});conv.pb({4,-1});conv.pb({5,2});conv.pb({6,-1});conv.pb({7,-1});conv.pb({8,8});conv.pb({9,-1});
    ll t;
    cin>>t;
    while(t--)
    {
        solve(conv);
        cout<<"\n";
    }
    return 0;
}
