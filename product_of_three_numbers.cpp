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
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

ll power(ll x, ll y, ll p=(ll)(1e9+7))
{
    ll res = 1;  
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2    
        x = (x*x) % p;
    }
    return res;
}
ll dist=0;
vi primeFactors(ll n)
{
    vi ans;
    // Prll the number of 2s that divide n
    if(n%2==0)
    {
        dist++;
    }
    while (n % 2 == 0)
    {
        ans.pb(2);
        n = n/2;

    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0)
        {
            dist++;
        }
        while (n % i == 0)
        {
            ans.pb(i);
            n = n/i;
        }
    }
    if (n > 2)
    {
        dist++;
        ans.pb(n);
    }

    sort(ans.begin(),ans.end());
    return ans;
}
void  solve()
{
    ll n;cin>>n;
    vi arr=primeFactors(n);
    vi ans;
    ll count=3;
    if(dist>=3)    
    {
        ans.pb(arr[0]);
        // if(arr[0]!=arr[1])
        // count--;

        REP(i,1,arr.size())
        {
            if(count==1)
            {
                ans[ans.size()-1]*=arr[i];
            }
            else if(arr[i]==arr[i-1])
            {
                ans[ans.size()-1]*=arr[i];
            }
            else
            {
                ans.pb(arr[i]);
                count--;
            }
        }
    }
    else if(dist==1)
    {
        if(arr.size()<6)
        {
            cout<<"NO";
            dist=0;
            return;
        }
        else
        {
            ans.pb(arr[0]);
            ans.pb(arr[1]*arr[2]);
            ans.pb(arr[3]);
            REP(i,4,arr.size())
            {
                ans[2]*=arr[i];
            }
        }
    }
    else if(dist==2)
    {
        if(arr.size()<4)
        {
            cout<<"NO";
            dist=0;
            return;
        }
        else
        {
            ans.pb(arr[0]);
            ans.pb(arr[arr.size()-1]);
            ans.pb(arr[1]);
            REP(i,2,arr.size()-1)
            {
                ans[2]*=arr[i];
            }
        }
    }
    cout<<"YES\n";
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
    dist=0;
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
