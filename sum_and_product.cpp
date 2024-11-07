#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
bool isInteger(double N)
{
    ll X = N;
    double temp2 = N - X;
 
    if (temp2 > (double)0.0) {
        return false;
    }
    return true;
}
long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
void solve()
{
    ll n;cin>>n;
    vi arr(n) ;
    map<ll,ll> fre;
    REP(i,0,n)
    {
        cin>>arr[i];
        fre[arr[i]]++;
    }
    ll q;cin>>q;
    vector<pii> query;
    REP(i,0,q)
    {
        ll b,c;cin>>b>>c;
        b*=-1;

        double d=(double)my_sqrt((ll)((double)(b*b)-4*c));
        if(d<(double)0)
        {
            cout<<0<<" ";
            continue;
        }
        else if(d>=(double)0)
        {
            ll root1=(double)(-b+d)/(double)2;
            ll root2=(double)(-b-d)/(double)2;

            if(root1+root2 == (-b) && root1*root2==c)
            {
                ll r1=root1;
                ll r2=root2;
                ll val=0;
                if(root1==root2)
                {
                    cout<<(fre[root1]*(fre[root2]-1))/2<<" ";
                }
                else
                {
                   cout<<fre[root1]*fre[root2]<<" ";
                }
                continue;
            }
            else
            {
                cout<<0<<" ";
                continue;
            }   
        }
    }
    return;

}
int main()
{
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
