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
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    int  n,m,x,y,di;
    cin>>n>>m>>x>>y>>di;
    pii l,r,u,d;
    if(y-di>0)//left
    {
        l.ff=x;
        l.ss=y-di;
    }
    else
    {
        l.ss=1;
        l.ff=x;
    }

    if(y+di<=m)//right
    {
        r.ss=y+di;
        r.ff=x;
    }
    else
    {
        r.ff=x;
        r.ss=m;
    }

    if(x-di>0)//up
    {
        u.ff=x-di;
        u.ss=y;
    }
    else
    {
        u.ff=1;
        u.ss=y;
    }

    if(x+di<=n)//down
    {
        d.ff=x+di;
        d.ss=y;
    }
    else
    {
        d.ff=n;
        d.ss=y;
    }

    // if down is blocked and up or right is blocked then not possible else possible
    bool down=false,right=false,up=false,left=false;
    if(l.ss==1)
    {
        left=1;
    }
    if(r.ss==m)
    {
        right=1;
    }
    if(u.ff==1)
    {
        up=1;
    }
    if(d.ff==n)
    {
        down=1;
    }
    if(left && ( up || right))
    {
        cout<<-1;
        return;
    }
    if(up && (left || down))
    {
        cout<<-1;
        return;
    }
    if(down && (right || up))
    {
        cout<<-1;
        return;
    }
    if(right && (down || left))
    {
        cout<<-1;
        return;
    }
    cout<<m+n-2;
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