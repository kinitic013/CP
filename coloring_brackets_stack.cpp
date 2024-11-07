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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n;cin>>n;
    string arr;cin>>arr;
    ll check=0;
    REP(i,0,n)
    {
        if(arr[i]=='(')
        check++;
        else
        check--;
    }
    if(check!=0)
    {
        cout<<-1;
        return;
    }
    ll count=0;
    ll one=0;// open with (
    ll two=0;// open with )
    vi ans(n,0);
    bool flag=0;
    REP(i,0,n)
    {
        if(arr[i]=='(')
        {
            if(two==0)
            {
                one++;
                ans[i]=1;
                continue;
            }
            else
            {
                two--;
                flag=1;
                ans[i]=2;
                continue;
            }
        }
        else 
        {
            if(one==0)
            {
                two++;
                flag=1;
                ans[i]=2;
                continue;
            }
            else
            {
                one--;
                ans[i]=1;
                continue;
            }
        }

    }
    flag=0;
    REP(i,0,n-1)
    {
        if(ans[i]!=ans[i+1])
        flag=1;        
    }
    if(flag)
    cout<<2;
    else
    cout<<1;
    cout<<endl;
    REP(i,0,n)
    {
        if(flag)
        {
            cout<<ans[i]<<" ";
        }
        else
        {
            cout<<1<<" ";
        }
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
