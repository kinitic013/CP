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
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}

//     REP(i,0,n)
//     {
//         ll ele;
//         cin>>ele;
//         x.pb(ele);
//     }

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    string a,s;
    vi result;
    cin>>a>>s;
    ll i=a.size()-1;
    ll j=s.size()-1;
    while(i>=0 && j>=0)
    {
        ll num=0;
        if(a[i]>s[j])
        {
            if(j==0)
            {

            }
            if(s[j-1]-'0'!=1)
            {
                cout<<-1;
                return;
            }
            num=((s[j-1]-'0')*10+(s[j]-a[i]));
            result.pb(num);
            i--;
            j-=2;
        }
        else
        {
            result.pb(s[j]-a[i]);
            i--;
            j--;
        }
    }
    while(i>=0)
    {
        cout<<-1;
        return;
    }
    while(j>=0)
    {
        result.pb(s[j]-'0');
        j--;
    }

    for(ll k=result.size()-1;k>=0;k--)
    {
        if(result[k]!=0)
        {
            break;
        }
        result.pop_back();
        if(k==0)
        {
            result.pb(0);
        }
    }
    reverse(result.begin(),result.end());
    REP(k,0,result.size())
    {
        cout<<result[k];
    }

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