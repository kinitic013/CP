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
    string arr,brr;cin>>arr>>brr;
    ll n = arr.size();
    ll t,q;cin>>t>>q;
    ll time = 0;
    ll notEqual = 0;
    REP(i,0,n)
    {
        if(arr[i] != brr[i])
        {
            notEqual++;
        }
    }

    queue<pii> que;
    REP(i,0,q)
    {
        time++;
        while(!que.empty() && que.front().second<=time)
        {
            if(arr[que.front().first]!=brr[que.front().first])
            {
                notEqual++;
            }
            que.pop();
        }
        
        ll query;cin>>query;
        if(query == 1)
        {
            ll pos;cin>>pos;
            pos--;
            if(arr[pos]!=brr[pos])
            notEqual--;

            que.push({pos,time+t});
        }
        else if(query == 2)
        {
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            y1--;
            y2--;

            if(arr[y1]!=brr[y1])
            notEqual--;
            if(arr[y2]!=brr[y2])
            notEqual--;

            if(x1 == x2)
            {
                if(x1 == 1)
                swap(arr[y1],arr[y2]);
                else
                swap(brr[y1],brr[y2]);
            }
            else
            {
                if(x1 == 1)
                {
                    char temp = brr[y2];
                    brr[y2] = arr[y1];
                    arr[y1] = temp;
                }
                else if( x1 == 2)
                {
                    char temp = brr[y1];
                    brr[y1] = arr[y2];
                    arr[y2] = temp;
                }
            }

            if(arr[y1] != brr[y1])
            {
                notEqual++;
            }
            if(arr[y2] != brr[y2])
            {
                notEqual++;
            }

        }
        else 
        {
            if(notEqual>=1)
            cout<<"NO"<<endl;
            else
            cout<<"YES"<<endl;
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
