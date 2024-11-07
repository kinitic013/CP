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
    ll n,p;
    cin>>n>>p;
    vector<pii> arr;// curr_val,<firsttypeindex>
    ll sum=0;
    vector<pair<ll,pii>> list;// val of t, pos. of element that is changed, ele with which it's changed
    REP(i,0,n)
    {
        ll ele;
        cin>>ele;
        sum+=ele;
        arr.push_back({ele,-1});
    }
    REP(i,0,p)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll ele1,ele2;
            cin>>ele1>>ele2;
            list.push_back(mp(t,mp(ele1,ele2)));
        }
        else
        {
            ll ele;
            cin>>ele;
            list.push_back(mp(t,mp(-1,ele)));

        }
    }
    // imput done
    pii type2=mp(-1,-1);//<secondtypeindex,secondtypevalue>
    REP(i,0,p)
    {
        ll x=list[i].ss.ss;// replacing value
        ll idx=list[i].ss.ff-1;// replacing index
        if(list[i].ff==1)// if t==1
        {
            if(type2.first!=-1)// type2 cases have been there for atleast once
            {
                if(arr[idx].ss>type2.ff)// checking wheather last change was by type1 or type2
                {                         
                    sum+=(x-arr[idx].ff);
                    arr[idx].ff=x;
                    arr[idx].ss=i;
                }
                else
                {
                    sum+=(x-type2.ss);
                    arr[idx].ff=x;
                    arr[idx].ss=i;
                }
            }
            else
            {
                sum+=(x-arr[idx].ff);
                arr[idx].ff=x;
                arr[idx].ss=i;
            }
        }
        else
        {            
            sum=x*n;
            type2.ff=i;
            type2.ss=x;
        }
        cout<<sum<<"\n";
    }
    return ;
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}