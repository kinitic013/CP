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
    ll n,x,y;cin>>n>>x>>y;
    vi fibo = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049, 12586269025};   
    ll t = 1;
    ll d = fibo[n];;
    ll l = 1;
    ll r = fibo[n+1];
    ll level = n;
    ll state = 1;//vertial check i.e. L ,R
    if((x<=d && x>=t) && (y<=r && y>=l))
    {

    }
    else
    {
        cout<<"NO";
        return;
    }
    while(level>1)
    {
        if(state)
        {
            pii range = {l,l+fibo[level]-1};
            if(l+fibo[level]-1>r)
            {
                cout<<"NO";
                return;
            }

            if((x<=d && x>=t) && (y<=range.ss && y>=range.ff))// inside this 
            {
                range = {r-fibo[level]+1,r};
                if((x<=d && x>=t) && (y<=range.ss && y>=range.ff)) // inside this
                {
                    cout<<"NO";
                    return;
                }
                r = r-fibo[level];
                state = 0;
                level--;
            }
            else
            {
                l = l+fibo[level];
                state = 0;
                level--;
                continue;
            }
        }
        else
        {
            pii range = {t,t+fibo[level]-1};
            if(t+fibo[level]-1>d)
            {
                cout<<"NO";
                return;
            }
            if((y<=r && y>=l) && (x<=range.ss && x>=range.ff))// inside this 
            {
                range = {d-fibo[level]+1,d};
                if((x<=range.ss && x>=range.ff) && (y<=r && y>=l)) // inside this
                {
                    cout<<"NO";
                    return;
                }
                d = d - fibo[level];
                state = 1;
                level--;
            }
            else
            {
                t = t+fibo[level];
                state = 1;
                level--;
                continue;
            }
        }
    }
    cout<<"YES";
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
