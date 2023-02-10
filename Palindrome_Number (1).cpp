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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi list;REP(i,0,n){ll ele;cin>>ele;list.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    ll n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (ll i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}
 
// Function for finding difference of larger numbers

string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
    ll n1 = str1.length(), n2 = str2.length();
    ll diff = n1 - n2;
    ll carry = 0;
 
    // Traverse from end of both strings
    for (ll i = n2 - 1; i >= 0; i--) {
        // compute difference of
        // current digits and carry
        ll sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of str1[]
    for (ll i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        ll sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) // remove preceding 0's
            str.push_back(sub + '0');
        carry = 0;
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}


void  solve()
{
    ll n;
    cin>>n;
    string str;
    cin>>str;
    string str1;
    REP(i,0,n+1)
    {
        str1.pb('1');
    }
    string str2;
    REP(i,0,n)
    {
        str2.pb('9');
    }

    if(str[0]=='9')
    {
       string ans=findDiff(str,str1); 
       cout<<ans;
       return;
    }
    string ans=findDiff(str,str2);
    cout<<ans;
    return ;
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