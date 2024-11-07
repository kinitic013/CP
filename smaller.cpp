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
void  solve()
{
    ll q;cin>>q;
    vi s(26,0),t(26,0);
    s[0]=1;t[0]=1;
    ll lens=1,lent=1;
    REP(j,0,q)
    {
        ll d,k;
        string x;
        cin>>d>>k>>x;
        if(d==1)
        {
            lens+=k*x.size();
        }
        else
        {
            lent+=k*x.size();
        }
        REP(i,0,x.size())
        {
            if(d==1)
            {
                s[x[i]-'a']+=k;
            }
            else
            {
                t[x[i]-'a']+=k;
            }
        }
        ll flag=0;
        REP(i,0,26)
        {
            if(s[i]>=1)
            {
                REP(j,i+1,26)
                {
                    if(t[j]>=1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
                ll tag=0;
                REP(j,i+1,26)
                {
                    if(s[j]>0)
                    {
                        tag=1;
                        break;
                    }
                }
                if(s[i]<t[i] && tag==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        cout<<"NO\n";
    }
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

        // ll flag=0;
        // ll currs=lens,currt=lent;
        // ll i=0;
        // for(;i<26;i++)
        // {
        //     if(s[i]>t[i])
        //     {
        //         flag=1;
        //         break;
        //     }
        //     else if(s[i]<t[i])
        //     break;

        // }
        // i++;
        // ll flag1=0;
        // if(flag)
        // {
        //     for(;i<26;i++)
        //     {
        //         if(t[i]>0)
        //         {
        //             flag1=1;
        //             break;
        //         }
        //     }
        //     if(flag1)
        //     {
        //         cout<<"YES\n";
        //         continue;
        //     }
        // }
        // flag1=0;
        // i=25;
        // for(;i>=0;i--)
        // {
        //     if(s[i]<t[i])
        //     {
        //         flag=1;
        //         break;
        //     }
        // }
        // i--;
        // if(flag)
        // {
        //     for(;i>=0;i--)
        //     {
        //         if(s[i]>0)
        //         {
        //             flag1=1;
        //             break;
        //         }
        //     }
        //     if(flag1)
        //     {
        //         cout<<"YES\n";
        //         continue;
        //     }

        // }

        // cout<<"NO\n";