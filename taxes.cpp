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
#define endl '\n'
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
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
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

void  solve()
{
    ll m,n;cin>>n>>m;
    string arr;
    cin>>arr;
    vi prefix1(n,0); vi prefix2(n,0);
    vi one(n,0); vi zero(n,0);
    ll MOD1=(ll)(1e9+7); ll MOD2=(ll)(1e9+9);
    ll p1=1;ll p2=1;
    ll hash1=0; ll hash2=0;
    REP(i,0,n)
    {
        if(arr[i]=='0')
        {
            if(i==0)
            {
                one[i]=0;
                zero[i]=1;
            }
            else
            {
                zero[i]=zero[i-1]+1;
                one[i]=one[i-1];
            }
        }
        else
        {
            if(i==0)
            {
                one[i]=1;
                zero[i]=0;
            }
            else
            { 
                one[i]=one[i-1]+1;
                zero[i]=zero[i-1];
            }
        }
        ll curr1=((arr[i]-'0'+1)*p1)%MOD1;
        hash1=(curr1+hash1)%MOD1;
        prefix1[i]=hash1;
        p1=(p1*31)%MOD1;

        // ll curr2=((arr[i]-'0'+1)*p2)%MOD2;
        // hash2=(curr2+hash2)%MOD2;
        // prefix2[i]=hash2;
        // p2=(p2*37)%MOD2;
    }
    set<ll> ans;
    REP(i,0,m)
    {
        ll l,r;cin>>l>>r;
        l--;r--;
        if(l==r)
        {
            // ans.insert({prefix1[n-1],prefix2[n-1]});
            ans.insert(prefix1[n-1]);
            continue;
        }
        else
        {
            ll z=zero[r];
            if(l!=0)
            z-=zero[l-1];

            ll o=one[r];
            if(l!=0)
            o-=one[l-1];

            ll h1=((power(31,o)-1)%MOD1);
            h1=(h1*(233333335))%MOD1;
            h1=(h1*((power(31,l+z))%MOD1))%MOD1;
            h1=(h1*2)%MOD1;

            ll h_1=((power(31,z)-1)%MOD1);
            h_1=(h_1*(233333335))%MOD1;
            h_1=(h_1*((power(31,l))%MOD1))%MOD1;

            h1=(h1+h_1)%MOD1;

            ll val1=(prefix1[n-1]-prefix1[r]+MOD1)%MOD1;
            if(l!=0)
            val1=(val1+prefix1[l-1])%MOD1;

            val1=(val1+h1)%MOD1;

            // ll h2=((power(37,o)-1)%MOD2);
            // h2=(h2*(972222231))%MOD2;
            // h2=(h2*((power(37,l+z))%MOD2))%MOD2;
            // h2=(h2*2)%MOD2;

            // ll h_2=((power(37,z)-1)%MOD2);
            // h_2=(h_2*(972222231))%MOD2;
            // h_2=(h_2*((power(37,l))%MOD2))%MOD2;

            // h2=(h2+h_2)%MOD2;

            // ll val2=(prefix2[n-1]-prefix2[r]+MOD2)%MOD2;
            // if(l!=0)
            // val2=(val2+prefix2[l-1])%MOD2;

            // val2=(val2+h2)%MOD2;

            // ans.insert({val1,val2});

            ans.insert(val1);
        }
    }
    cout<<ans.size();
}
int main()
{
    fast();
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}