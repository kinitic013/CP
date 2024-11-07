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
string decToBinary(ll n)
{
	// Size of an lleger is assumed to be 32 bits
    string arr;
	for (ll i = 63; i >= 0; i--) {
		ll k = n >> i;
		if (k & 1)
			arr.pb('1');
		else
			arr.pb('0');
	}
    return arr;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
  
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
  
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
  
    return dec_value;
}
void solve()
{
    ll n,x;cin>>n>>x;
    if(x>n)
    {
        cout<<-1;
        return;
    }

    string from,to;
    from = decToBinary(n);
    to = decToBinary(x);
    ll i = from.size()-1;
    ll carry = 0;
    bool one = false;
    while(i>=0)
    {
        if(from[i] == '0' && to[i] == '1')
        {
            cout<<-1;
            return;
        }
        if(carry == 1)
        {
            if(from[i] == '1' && to[i] == '1')
            {
                one = 1;
                i--;
                continue;
            }
            else if(from[i] == '0' && to[i] == '0')
            {
                if(one)
                {
                    cout<<-1;
                    return;
                }
                carry = 0;
                from[i] = '1';
                from[i+1] = '#';
                i--;
            }
            else if(from[i] == '1' && to[i] == '0')
            {
                i--;
                continue;
            }
        }
        else
        {
            if(from[i] == '1' && to[i] == '1')
            {
                one = 1;
                i--;
                continue;
            }
            else if(from[i] == '0' && to[i] == '0')
            {
                // if(one)
                // {
                //     cout<<-1;
                //     return;
                // }
                // carry = 0;
                // from[i] = '1';
                // from[i-1] = '#';
                i--;
            }
            else if(from[i] == '1' && to[i] == '0')
            {
                carry = 1;
                i--;
                continue;
            }
        }
    }
    bool flag =0;
    REP(i,0,from.size())
    {
        if(flag)
        from[i] = '0';
        else
        {
            if(from[i] == '#')
            {
                flag = 1;
                from[i] = '0';
            }
        }
    }
    ll ans = binaryToDecimal(from);
    cout<<ans;
    return ;
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