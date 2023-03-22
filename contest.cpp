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
void  solve()
{
    ll n,m;cin>>n>>m;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    string dr;
    cin>>dr;
    string curr=dr;
    ll count=0;
    // if(n==m)
    // {
    //     ll s1=a+b;
    //     ll s2=n+s1;
    //     ll diff1=a-b;
    //     ll diff2=b-a;

    //     if((c+d)==s1 || (c+d)==s2 || (c-d)==diff1 || (d-c)==diff2)
    //     {
    //         cout<<
    //     }


    // }
    ll counter=0;
    ll cf=a; ll cs=b;
    if(a==c && b==d)
    {
        cout<<count<<endl;
        return;
    }
    if(a==1 && b==1 && dr=="UL")
    {
        dr="DR";
        count++;
    }
    else if(a==1 && b==m && dr=="UR")
    {
        dr="DL";count++;
    }
    else if(a==n && b==1 && dr=="DL")
    {
        dr="UR";count++;
    }
    else if(a==n && b==m && dr=="DR")
    {
        dr="UL";count++;
    }
    while(1)
    {
        if(a==c && b==d)
        {
            cout<<count<<endl;
            return;
        }
        if(cf==a && cs==b)
        {
            counter++;
        }
        if(counter>=5)
        {
            break;
        }

        if(b==1 && a!=1 && a!=n)//Left
        {
            if(dr[1]=='L')
            {
                dr[1]='R';
                count++;
            }
        }
        else if(a==1 && b!=1 && b!=m)// up
        {
            if(dr[0]=='U')
            {
                dr[0]='D';
                count++;
            }
        }
        else if(b==m && a!=1 && a!=n)//right
        {
            if(dr[1]=='R')
            {
                dr[1]='L';
                count++;
            }

        }
        else if(a==n && b!=1 && b!=m)//down
        {
            if(dr[0]=='D')
            {
                dr[0]='U';
                count++;
            }
        }
        //corners
        if(a==1 && b==1 )
        {
            count++;
            if(dr=="UR")
            {
                dr[0]='D';
            }
            else if(dr=="DL")
            {
                dr[1]='R';
            }
            else if(dr=="UL")
            {
                dr="DR";
            }
            else
            {
                count--;
            }
        }
        else if(a==1 && b==m )
        {
            count++;
            if(dr=="UL")
            {
                dr[0]='D';
            }
            else if(dr=="DR")
            {
                dr[1]='L';
            }
            else if(dr=="UR")
            {
                dr="DL";
            }
            else
            {
                count--;
            }
        }
        else if(a==n && b==1)
        {
            count++;
            if(dr=="UL")
            {
                dr[1]='R';
            }
            else if(dr=="DR")
            {
                dr[0]='U';
            }
            else if(dr=="DL")
            {
                dr="UR";
            }
            else
            {
                count--;
            }
        }
        else if(a==n && b==m)
        {
            count++;
            if(dr=="UR")
            {
                dr[1]='L';
            }
            else if(dr=="DL")
            {
                dr[0]='U';
            }
            else if(dr=="DR")
            {
                dr="UL";
            }
            else
            {
                count--;
            }
        }
        if(a==c && b==d)
        {
            cout<<count<<endl;
            return;
        }
        if(dr=="UR")
        {
            a--;
            b++;
        }
        else if(dr=="UL")
        {
            a--;
            b--;
        }
        else if(dr=="DR")
        {
            a++;
            b++;
        }
        else if(dr=="DL")
        {
            a++;
            b--;
        }
    }
    cout<<"-1\n";
    return;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
