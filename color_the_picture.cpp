#include<bits/stdc++.h>
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define pb push_back
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
bool checker(vi a,ll count,ll k,ll m)
{
    ll odd=0;
    ll total=0;
    ll flag=0;
    REP(i,0,k)
    {
        if(a[i]>1)
        {
            total+=(a[i]/2)*2;
            if(a[i]>=3)
            flag=1;
            a[i]=a[i]%2;
            if(a[i]==1)
            odd++;
        }
        else
        a[i]=-1;
    }
    if(m&1)
    {
        if(total>=count && flag==1)
        {
            return true;
        }
        else if(total<count)
        {
            if(odd>=count-total)
            return true;
        }
    }
    else 
    {
        if(total>=count)
        {
            return true;
        }
        else
        {
            if(odd>=count-total)
            return true;
        }
    }
    return false;
}
void  solve()
{
    ll n,m,k;cin>>n>>m>>k;
    vi arr(k);
    vi an(k),am(k);
    REP(i,0,k)
    {
        cin>>arr[i];
        an[i]=arr[i]/n;
        am[i]=arr[i]/m;
    }
    ll countn=m;
    ll countm=n;
    ll nodd=0,modd=0;
    //checking with n
    ll flag=0;
    if(checker(an,countn,k,m) || checker(am,countm,k,n))
    cout<<"Yes";
    else
    cout<<"No";
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
