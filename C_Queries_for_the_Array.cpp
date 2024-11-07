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
ll solve()
{
    string arr;cin>>arr;
    ll n = arr.size();
    stack<pair<ll,ll>> s;
    char state = '1';
    ll sorted = 1; // defines maximum sorted sequence present
    ll unsorted = INT_MAX; // min unsorted sequence present 
    ll size = 0;
    REP(i,0,n)
    {
        if(arr[i] == '+')
        {
            size++;
            if(s.empty())
            {
                s.push({10,'1'});
                state = '1';
            }
            else
            {
                pii top = s.top();
                if(top.ss == '0')
                {
                    s.push({10,'0'});
                    state = '0';
                }
                else
                {
                    s.push({10,'?'});
                    state = '?';
                }
            }
        }
        else if(arr[i] == '-')
        {
            pii top = s.top();
            s.pop();
            size--;
            if(s.empty())
            {
                state = '1';
            }
            else
            {
                pii t = s.top();
                state = t.ss;
                if(size>=unsorted)
                {
                    unsorted = size;
                }
                else
                {
                    unsorted = INT_MAX;
                }

                if(sorted>=size)
                {
                    sorted = size;
                }
            }
        }
        else if(arr[i] == '1')
        {
            state = '1';
            if(s.empty())
            continue;
            else
            {
                if(size>=unsorted)
                {
                    return 0;
                }
                else
                {
                    sorted = size;
                    unsorted = INT_MAX;
                }

                if(s.top().ss == '0')
                {
                    return 0;
                }
                else
                {
                    s.top().ss = '1';
                }

            }
        }
        else // arr[i] = '0'
        {
            state = 0;
            if(s.empty())
            return 0;
            else
            {
                if(size <= sorted)
                {
                    return 0;
                }
                else
                {
                    unsorted = size;
                }

                if(s.top().ss == '1')
                {
                    return 0;
                }
                else
                {
                    s.top().ss = '0';
                }
            }
        }
    }
    return 1;
}
int main()
{
    fast();
    ll t;
    cin >> t;
    while (t--)
    {
        if(solve())
        cout<<"YES";
        else
        cout<<"NO";
        
        cout << endl;
    }
    return 0;
}