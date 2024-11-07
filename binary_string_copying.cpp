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
    vi prefix1(n,0);    vi prefix2(n,0);
    vi one(n,0); vi zero(n,0);
    vi sum1(n,0);     vi sum2(n,0);
    ll hash1=0;ll p1=1; ll p2=1; ll hash2=0;
    ll MOD1=(ll)(1e9+7); ll MOD2=(ll)(1e9+9);
    REP(i,0,n)
    { 
        if(arr[i]=='1')
        {
            if(i!=0)
            {
                one[i]=1+one[i-1];
                zero[i]=zero[i-1];
            }
            else
            {
                one[i]=1;
                zero[i]=0;
            }

        }
        else
        {
            if(i!=0)
            {
                one[i]=one[i-1];
                zero[i]=1+zero[i-1];
            }
            else
            {
                one[i]=0;
                zero[i]=1;
            }
        }

        ll curr1=((arr[i]-'0'+1)*p1)%MOD1;
        hash1=(hash1+curr1)%MOD1;

        prefix1[i]=hash1;

        if(i==0)
        {
            sum1[i]=p1;
        }
        else
        {
            sum1[i]=(sum1[i-1]+p1)%MOD1;
        }
        p1=(p1*31)%MOD1;

        ll curr2=((arr[i]-'0'+1)*p2)%MOD2;
        hash2=(hash2+curr2)%MOD2;
 
        prefix2[i]=hash2;
 
        if(i==0)
        {
            sum2[i]=p2;
        }
        else
        {
            sum2[i]=(sum2[i-1]+p2)%MOD2;
        }
        p2=(p2*31)%MOD2;


        


    }
    set<pii> ans;
    REP(i,0,m)
    {
        ll l,r;cin>>l>>r;
        l--;r--;
        ll ZERO=0,ONE=0;

        ZERO=zero[r];
        if(l!=0)
        ZERO-=zero[l-1];
 
        ONE=one[r];
        if(l!=0)
        ONE-=one[l-1];

        if(l==r || ZERO==0 || ONE==0)
        {
            ans.insert({prefix1[n-1],prefix2[n-1]});
            continue;
        }
        ll change1=(2*sum1[r])%MOD1;
        change1=(change1-sum1[l+ZERO-1]+MOD1)%MOD1;
        if(l!=0)
        {
            change1=(change1-sum1[l-1]+MOD1)%MOD1;
        }

        ll newString1=(prefix1[n-1]-prefix1[r]+MOD1)%MOD1;
        if(l!=0)
        {
            newString1=(newString1+prefix1[l-1])%MOD1;
        }
        newString1=(newString1+change1)%MOD1;


        ll change2=(2*sum2[r])%MOD2;
        change2=(change2-sum2[l+ZERO-1]+MOD2)%MOD2;
        if(l!=0)
        {
            change2=(change2-sum2[l-1]+MOD2)%MOD2;
        }

        ll newString2=(prefix2[n-1]-prefix2[r]+MOD2)%MOD2;
        if(l!=0)
        {
            newString2=(newString2+prefix2[l-1])%MOD2;
        }
        newString2=(newString2+change2)%MOD2;

        ans.insert({newString1,newString2});
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
