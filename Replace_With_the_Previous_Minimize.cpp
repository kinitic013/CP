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
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n,k;cin>>n>>k;
    string arr;cin>>arr;
    char v=arr[0];
    if(k>=25)
    {
        REP(i,0,n)
        cout<<'a';

        return;
    }
    else
    {
        ll val=min(k,(ll)arr[0]-'a');
        if(arr[0]-'a'>=k)
        {
            REP(i,0,n)
            {
                if(arr[i]<=v)
                {
                    if(arr[i]>v-k)
                    arr[i]=v-k;
                    
                }
            }
            cout<<arr;
            return;
        }
        else
        {
            char v=arr[0];
            k-=arr[0]-'a';
            char v2;bool flag=0;
            char v1;
            REP(i,0,n)
            {
                if(arr[i]>v)
                {
                    ll diff=arr[i]-v;
                    if(diff<=k)
                    {
                        k-=diff;
                        v=arr[i];
                    }
                    else
                    {
                        flag=1;
                        v1=arr[i]-k;
                        v2=arr[i];
                        break;
                    }
                }
            }
            REP(i,0,n)
            {
                if(arr[i]<=v)
                {
                    arr[i]='a';
                }
                else
                {
                    if(flag && arr[i]>=v1 && arr[i]<=v2)
                    {
                        arr[i]=v1;
                    }
                }
            }
            cout<<arr;
            return;
        }

    }
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
