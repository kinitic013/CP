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
//#define endl '\n'
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
    ll l=1;
    ll r=n;
    ll pos;
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    cin>>pos;
    while(r-l>1)
    {
        if(r-l == 2)
        {
            if(l == pos)
            {
                cout<<"? "<<l+1<<" "<<r<<endl;
                cout.flush();
                ll idx ;cin>>idx;
                cout<<"! "<<r+l+1 - idx;
                return;
            }
            else if(r == pos)
            {
                cout<<"? "<<l<<" "<<l+1<<endl;
                cout.flush();
                ll idx ;cin>>idx;
                cout<<"! "<<2*l+1 - idx;
                return;
            }
            else
            {
                cout<<"? "<<l<<" "<<l+1<<endl;
                cout.flush();
                ll idx ;cin>>idx;
                if(idx == pos)
                {
                    r=l+1;
                    continue;
                }
                else
                {
                    cout<<"! "<<r;
                    return;
                }
            }
        }

        
        ll mid = (l+r)/2;
        ll low ,high;
        if(pos<=mid)// in left
        {
            cout<<"? "<<l<<" "<<mid<<endl;
            cout.flush();
            cin>>low;
            if(low == pos)
            {
                r = mid;
                continue;
            }
            else
            {
                cout<<"? "<<mid+1<<" "<<r<<endl;
                cout.flush();
                cin>>high;
                pos = high;
                l = mid+1;
                continue;
            }
        }
        else
        {
            cout<<"? "<<mid+1<<" "<<r<<endl;
            cout.flush();
            cin>>high;
            if(high == pos)
            {
                l = mid+1;
                continue;
            }
            else
            {
                cout<<"? "<<l<<" "<<mid<<endl;
                cout.flush();
                cin>>low;
                pos = low;
                r = mid;
                continue;
            }
        };
    }
    cout<<"! "<<r+l-pos;
    cout.flush();
    return;
}
int main()
{
    fast();
    // ll t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
