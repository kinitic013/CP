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
#define vvi vector<vi>
#define vb vector<bool>
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
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
void solve()
{
    ll n;cin>>n;
    vi pos,neg;
    vi res;
    bool allZero = true;

    REP(i,0,n)
    {
        ll ele;cin>>ele;
        if(ele>0) allZero = 0;
        if(ele>0) pos.pb(ele);
        else if(ele<0) neg.pb(ele);
        else res.pb(ele);
    }
    if(allZero)
    cout<<"No"<<endl;
    else
    {
        ll curr = 0;
        ll i = 0;
        ll j = 0;

        while(1)
        {
            if(curr>=0)
            {
                while(j<neg.size() && curr>=0)
                {
                    res.pb(neg[j]);
                    curr+=neg[j];
                    j++;
                }
            }
            else 
            {
                while (i<pos.size() && curr<0)
                {
                    res.pb(pos[i]);
                    curr+=pos[i];
                    i++;
                }
            }
            if(j==neg.size() && i == pos.size())
            {
                break;
            }
        }

        cout<<"Yes"<<endl;
        REP(i,0,res.size())
        {
            cout<<res[i]<<" ";
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
