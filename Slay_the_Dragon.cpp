#include<bits/stdc++.h>
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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;cin>>n;vi arr;
    ll sum=0;
    REP(i,0,n)
    {
        ll ele ;cin>>ele;
        arr.pb(ele);
        sum+=ele;
    }
    cin>>m;
    sort(arr.begin(),arr.end());
    for(ll i=0;i<m;i++)
    {
        ll d,a;
        cin>>d>>a;
        ll add=lower_bound(arr.begin(),arr.end(),d)-arr.begin();bool flag=1;
        // just plus
        ll val1=0,val2=0;
        if(add>0)
        {
            val2=max(val2,d-arr[add-1]+max((ll)0,a-(sum-arr[add-1])));
        }
        else
        val2=LONG_LONG_MAX;
        if(add<n)
        {
            val1=max((ll)0,a-(sum-arr[add]));
        }
        else
        val1=LONG_LONG_MAX;
        cout<<min(val2,val1)<<endl;
    }

    return 0;
}
